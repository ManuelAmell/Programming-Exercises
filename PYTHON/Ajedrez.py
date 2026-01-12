import pygame
import sys
from typing import List, Tuple, Optional

pygame.init()

# Configuración
BOARD_WIDTH = 800
SIDEBAR_WIDTH = 250
WIDTH = BOARD_WIDTH + SIDEBAR_WIDTH
HEIGHT = 800
BOARD_SIZE = 8
TILE_SIZE = BOARD_WIDTH // BOARD_SIZE

# Colores mejorados
LIGHT_SQUARE = (238, 238, 210)
DARK_SQUARE = (118, 150, 86)
HIGHLIGHT_COLOR = (186, 202, 68, 160)
SELECTED_COLOR = (246, 246, 130, 200)
CHECK_COLOR = (231, 76, 60, 180)
WHITE_PIECE = (255, 255, 255)
BLACK_PIECE = (40, 40, 40)
OUTLINE_COLOR = (20, 20, 20)
SIDEBAR_BG = (45, 52, 54)
TEXT_COLOR = (236, 240, 241)
ACCENT_COLOR = (52, 152, 219)
WIN_COLOR = (46, 204, 113)
BOARD_BORDER = (30, 30, 30)

screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption('Ajedrez Profesional')
clock = pygame.time.Clock()

class Piece:
    PIECE_VALUES = {
        'Pawn': 1,
        'Knight': 3,
        'Bishop': 3,
        'Rook': 5,
        'Queen': 9,
        'King': 0
    }
    
    def __init__(self, color: str, pos: Tuple[int, int]):
        self.color = color
        self.pos = pos
        self.has_moved = False
    
    def get_value(self) -> int:
        return self.PIECE_VALUES.get(self.__class__.__name__, 0)
    
    def get_possible_moves(self, board) -> List[Tuple[int, int]]:
        return []
    
    def is_valid_move(self, new_pos: Tuple[int, int], board) -> bool:
        return new_pos in self.get_possible_moves(board)

class Pawn(Piece):
    def get_possible_moves(self, board) -> List[Tuple[int, int]]:
        moves = []
        row, col = self.pos
        direction = -1 if self.color == 'white' else 1
        
        # Movimiento adelante
        if 0 <= row + direction < 8 and board[row + direction][col] is None:
            moves.append((row + direction, col))
            # Doble movimiento inicial
            if not self.has_moved and board[row + 2*direction][col] is None:
                moves.append((row + 2*direction, col))
        
        # Capturas diagonales
        for dc in [-1, 1]:
            new_row, new_col = row + direction, col + dc
            if 0 <= new_row < 8 and 0 <= new_col < 8:
                target = board[new_row][new_col]
                if target and target.color != self.color:
                    moves.append((new_row, new_col))
        
        return moves
    
    def draw(self, surface):
        x, y = self.pos[1] * TILE_SIZE, self.pos[0] * TILE_SIZE
        color = WHITE_PIECE if self.color == 'white' else BLACK_PIECE
        shadow_color = (100, 100, 100, 100)
        highlight = (255, 255, 255, 180) if self.color == 'white' else (80, 80, 80)
        center_x, center_y = x + TILE_SIZE // 2, y + TILE_SIZE // 2
        
        # Sombra
        shadow = pygame.Surface((TILE_SIZE, TILE_SIZE), pygame.SRCALPHA)
        pygame.draw.ellipse(shadow, shadow_color, (center_x - x - 20, center_y - y + 25, 40, 12))
        surface.blit(shadow, (x, y))
        
        # Cabeza del peón (esfera)
        pygame.draw.circle(surface, color, (center_x, center_y - 18), 13)
        pygame.draw.circle(surface, highlight, (center_x - 4, center_y - 22), 4)
        pygame.draw.circle(surface, OUTLINE_COLOR, (center_x, center_y - 18), 13, 2)
        
        # Cuello
        pygame.draw.rect(surface, color, (center_x - 8, center_y - 8, 16, 8))
        
        # Cuerpo cónico
        points = [(center_x - 10, center_y), (center_x + 10, center_y),
                  (center_x + 14, center_y + 18), (center_x - 14, center_y + 18)]
        pygame.draw.polygon(surface, color, points)
        pygame.draw.polygon(surface, OUTLINE_COLOR, points, 2)
        
        # Base con grosor
        pygame.draw.ellipse(surface, color, (center_x - 18, center_y + 16, 36, 12))
        pygame.draw.ellipse(surface, OUTLINE_COLOR, (center_x - 18, center_y + 16, 36, 12), 2)

class Rook(Piece):
    def get_possible_moves(self, board) -> List[Tuple[int, int]]:
        moves = []
        row, col = self.pos
        
        # Direcciones: arriba, abajo, izquierda, derecha
        for dr, dc in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            for i in range(1, 8):
                new_row, new_col = row + dr*i, col + dc*i
                if not (0 <= new_row < 8 and 0 <= new_col < 8):
                    break
                if board[new_row][new_col] is None:
                    moves.append((new_row, new_col))
                elif board[new_row][new_col].color != self.color:
                    moves.append((new_row, new_col))
                    break
                else:
                    break
        return moves
    
    def draw(self, surface):
        x, y = self.pos[1] * TILE_SIZE, self.pos[0] * TILE_SIZE
        color = WHITE_PIECE if self.color == 'white' else BLACK_PIECE
        shadow_color = (100, 100, 100, 100)
        highlight = (255, 255, 255, 180) if self.color == 'white' else (80, 80, 80)
        center_x, center_y = x + TILE_SIZE // 2, y + TILE_SIZE // 2
        
        # Sombra
        shadow = pygame.Surface((TILE_SIZE, TILE_SIZE), pygame.SRCALPHA)
        pygame.draw.ellipse(shadow, shadow_color, (center_x - x - 22, center_y - y + 25, 44, 12))
        surface.blit(shadow, (x, y))
        
        # Cuerpo de la torre (rectángulo con textura)
        body_rect = pygame.Rect(center_x - 16, center_y - 12, 32, 30)
        pygame.draw.rect(surface, color, body_rect)
        pygame.draw.rect(surface, OUTLINE_COLOR, body_rect, 2)
        
        # Detalle de ventanas
        for i in range(2):
            pygame.draw.rect(surface, OUTLINE_COLOR, 
                           (center_x - 10 + i * 12, center_y, 8, 8), 1)
        
        # Almenas superiores (más detalladas)
        almena_width = 7
        for i in [-14, -5, 4, 13]:
            almena = pygame.Rect(center_x + i - almena_width//2, center_y - 24, almena_width, 12)
            pygame.draw.rect(surface, color, almena)
            pygame.draw.rect(surface, OUTLINE_COLOR, almena, 2)
            # Highlight
            pygame.draw.line(surface, highlight, 
                           (center_x + i - 2, center_y - 23), 
                           (center_x + i - 2, center_y - 15), 1)
        
        # Tope de almenas
        pygame.draw.rect(surface, color, (center_x - 18, center_y - 25, 36, 3))
        
        # Base con múltiples niveles
        pygame.draw.ellipse(surface, color, (center_x - 20, center_y + 16, 40, 10))
        pygame.draw.ellipse(surface, OUTLINE_COLOR, (center_x - 20, center_y + 16, 40, 10), 2)
        pygame.draw.rect(surface, color, (center_x - 18, center_y + 18, 36, 6))
        pygame.draw.rect(surface, OUTLINE_COLOR, (center_x - 18, center_y + 18, 36, 6), 2)

class Knight(Piece):
    def get_possible_moves(self, board) -> List[Tuple[int, int]]:
        moves = []
        row, col = self.pos
        knight_moves = [(-2,-1), (-2,1), (-1,-2), (-1,2), (1,-2), (1,2), (2,-1), (2,1)]
        
        for dr, dc in knight_moves:
            new_row, new_col = row + dr, col + dc
            if 0 <= new_row < 8 and 0 <= new_col < 8:
                target = board[new_row][new_col]
                if target is None or target.color != self.color:
                    moves.append((new_row, new_col))
        return moves
    
    def draw(self, surface):
        x, y = self.pos[1] * TILE_SIZE, self.pos[0] * TILE_SIZE
        color = WHITE_PIECE if self.color == 'white' else BLACK_PIECE
        shadow_color = (100, 100, 100, 100)
        highlight = (255, 255, 255, 180) if self.color == 'white' else (80, 80, 80)
        center_x, center_y = x + TILE_SIZE // 2, y + TILE_SIZE // 2
        
        # Sombra
        shadow = pygame.Surface((TILE_SIZE, TILE_SIZE), pygame.SRCALPHA)
        pygame.draw.ellipse(shadow, shadow_color, (center_x - x - 22, center_y - y + 25, 44, 12))
        surface.blit(shadow, (x, y))
        
        # Cabeza del caballo (forma más detallada)
        head_points = [
            (center_x - 8, center_y + 18),  # Base izquierda
            (center_x - 10, center_y + 5),  # Cuello
            (center_x - 6, center_y - 8),   # Nuca
            (center_x + 2, center_y - 22),  # Orejas
            (center_x + 12, center_y - 20), # Frente
            (center_x + 18, center_y - 10), # Hocico superior
            (center_x + 16, center_y - 2),  # Nariz
            (center_x + 18, center_y + 4),  # Hocico inferior
            (center_x + 12, center_y + 10), # Mandíbula
            (center_x + 8, center_y + 18),  # Base derecha
        ]
        
        pygame.draw.polygon(surface, color, head_points)
        pygame.draw.polygon(surface, OUTLINE_COLOR, head_points, 2)
        
        # Ojo del caballo
        pygame.draw.circle(surface, OUTLINE_COLOR, (center_x + 8, center_y - 12), 3)
        
        # Crin
        for i in range(3):
            pygame.draw.line(surface, OUTLINE_COLOR, 
                           (center_x - 2 + i*2, center_y - 18 + i*3),
                           (center_x - 6 + i*2, center_y - 14 + i*3), 2)
        
        # Highlight
        pygame.draw.circle(surface, highlight, (center_x + 10, center_y - 14), 2)
        
        # Base
        pygame.draw.ellipse(surface, color, (center_x - 20, center_y + 16, 40, 10))
        pygame.draw.ellipse(surface, OUTLINE_COLOR, (center_x - 20, center_y + 16, 40, 10), 2)
        pygame.draw.rect(surface, color, (center_x - 18, center_y + 18, 36, 6))
        pygame.draw.rect(surface, OUTLINE_COLOR, (center_x - 18, center_y + 18, 36, 6), 2)

class Bishop(Piece):
    def get_possible_moves(self, board) -> List[Tuple[int, int]]:
        moves = []
        row, col = self.pos
        
        # Diagonales
        for dr, dc in [(-1, -1), (-1, 1), (1, -1), (1, 1)]:
            for i in range(1, 8):
                new_row, new_col = row + dr*i, col + dc*i
                if not (0 <= new_row < 8 and 0 <= new_col < 8):
                    break
                if board[new_row][new_col] is None:
                    moves.append((new_row, new_col))
                elif board[new_row][new_col].color != self.color:
                    moves.append((new_row, new_col))
                    break
                else:
                    break
        return moves
    
    def draw(self, surface):
        x, y = self.pos[1] * TILE_SIZE, self.pos[0] * TILE_SIZE
        color = WHITE_PIECE if self.color == 'white' else BLACK_PIECE
        shadow_color = (100, 100, 100, 100)
        highlight = (255, 255, 255, 180) if self.color == 'white' else (80, 80, 80)
        center_x, center_y = x + TILE_SIZE // 2, y + TILE_SIZE // 2
        
        # Sombra
        shadow = pygame.Surface((TILE_SIZE, TILE_SIZE), pygame.SRCALPHA)
        pygame.draw.ellipse(shadow, shadow_color, (center_x - x - 20, center_y - y + 25, 40, 12))
        surface.blit(shadow, (x, y))
        
        # Mitra (parte superior puntiaguda)
        mitra_points = [
            (center_x, center_y - 24),      # Punta
            (center_x - 10, center_y - 12), # Izquierda
            (center_x + 10, center_y - 12), # Derecha
        ]
        pygame.draw.polygon(surface, color, mitra_points)
        pygame.draw.polygon(surface, OUTLINE_COLOR, mitra_points, 2)
        
        # Círculo decorativo en la punta
        pygame.draw.circle(surface, color, (center_x, center_y - 20), 5)
        pygame.draw.circle(surface, OUTLINE_COLOR, (center_x, center_y - 20), 5, 2)
        pygame.draw.circle(surface, highlight, (center_x - 2, center_y - 22), 2)
        
        # Ranura central
        pygame.draw.line(surface, OUTLINE_COLOR, 
                        (center_x, center_y - 20), 
                        (center_x, center_y - 8), 2)
        
        # Cuerpo cónico
        body_points = [
            (center_x - 12, center_y - 10),
            (center_x + 12, center_y - 10),
            (center_x + 15, center_y + 18),
            (center_x - 15, center_y + 18)
        ]
        pygame.draw.polygon(surface, color, body_points)
        pygame.draw.polygon(surface, OUTLINE_COLOR, body_points, 2)
        
        # Detalles decorativos en el cuerpo
        pygame.draw.line(surface, highlight, 
                        (center_x - 8, center_y - 8), 
                        (center_x - 11, center_y + 16), 2)
        
        # Base
        pygame.draw.ellipse(surface, color, (center_x - 20, center_y + 16, 40, 10))
        pygame.draw.ellipse(surface, OUTLINE_COLOR, (center_x - 20, center_y + 16, 40, 10), 2)
        pygame.draw.rect(surface, color, (center_x - 18, center_y + 18, 36, 6))
        pygame.draw.rect(surface, OUTLINE_COLOR, (center_x - 18, center_y + 18, 36, 6), 2)

class Queen(Piece):
    def get_possible_moves(self, board) -> List[Tuple[int, int]]:
        moves = []
        row, col = self.pos
        
        # Combinación de torre y alfil
        for dr, dc in [(-1,0), (1,0), (0,-1), (0,1), (-1,-1), (-1,1), (1,-1), (1,1)]:
            for i in range(1, 8):
                new_row, new_col = row + dr*i, col + dc*i
                if not (0 <= new_row < 8 and 0 <= new_col < 8):
                    break
                if board[new_row][new_col] is None:
                    moves.append((new_row, new_col))
                elif board[new_row][new_col].color != self.color:
                    moves.append((new_row, new_col))
                    break
                else:
                    break
        return moves
    
    def draw(self, surface):
        x, y = self.pos[1] * TILE_SIZE, self.pos[0] * TILE_SIZE
        color = WHITE_PIECE if self.color == 'white' else BLACK_PIECE
        shadow_color = (100, 100, 100, 100)
        highlight = (255, 255, 255, 180) if self.color == 'white' else (80, 80, 80)
        center_x, center_y = x + TILE_SIZE // 2, y + TILE_SIZE // 2
        
        # Sombra
        shadow = pygame.Surface((TILE_SIZE, TILE_SIZE), pygame.SRCALPHA)
        pygame.draw.ellipse(shadow, shadow_color, (center_x - x - 24, center_y - y + 25, 48, 12))
        surface.blit(shadow, (x, y))
        
        # Corona con múltiples puntas elaboradas
        crown_points = []
        num_peaks = 5
        for i in range(num_peaks):
            angle_base = -90 + (i * 360 / num_peaks)
            # Punta
            peak_angle = angle_base
            peak_x = center_x + 16 * pygame.math.Vector2(1, 0).rotate(peak_angle).x
            peak_y = center_y - 24 + 16 * pygame.math.Vector2(1, 0).rotate(peak_angle).y
            crown_points.append((peak_x, peak_y))
            
            # Valle
            if i < num_peaks - 1:
                valley_angle = angle_base + (360 / num_peaks / 2)
                valley_x = center_x + 10 * pygame.math.Vector2(1, 0).rotate(valley_angle).x
                valley_y = center_y - 24 + 10 * pygame.math.Vector2(1, 0).rotate(valley_angle).y
                crown_points.append((valley_x, valley_y))
        
        # Dibuja puntas decorativas de la corona
        for i in range(-20, 25, 11):
            # Esferas en las puntas
            sphere_y = center_y - 24 + abs(i) * 0.15
            pygame.draw.circle(surface, color, (int(center_x + i), int(sphere_y)), 6)
            pygame.draw.circle(surface, OUTLINE_COLOR, (int(center_x + i), int(sphere_y)), 6, 2)
            pygame.draw.circle(surface, highlight, (int(center_x + i - 2), int(sphere_y - 2)), 2)
        
        # Banda de la corona
        pygame.draw.ellipse(surface, color, (center_x - 18, center_y - 16, 36, 12))
        pygame.draw.ellipse(surface, OUTLINE_COLOR, (center_x - 18, center_y - 16, 36, 12), 2)
        
        # Cuerpo elegante
        body_points = [
            (center_x - 14, center_y - 8),
            (center_x + 14, center_y - 8),
            (center_x + 17, center_y + 18),
            (center_x - 17, center_y + 18)
        ]
        pygame.draw.polygon(surface, color, body_points)
        pygame.draw.polygon(surface, OUTLINE_COLOR, body_points, 2)
        
        # Detalles decorativos
        pygame.draw.line(surface, highlight, 
                        (center_x - 10, center_y - 6), 
                        (center_x - 13, center_y + 16), 3)
        
        # Joya central
        pygame.draw.circle(surface, (180, 50, 50), (center_x, center_y + 2), 4)
        pygame.draw.circle(surface, OUTLINE_COLOR, (center_x, center_y + 2), 4, 1)
        
        # Base majestuosa
        pygame.draw.ellipse(surface, color, (center_x - 22, center_y + 16, 44, 10))
        pygame.draw.ellipse(surface, OUTLINE_COLOR, (center_x - 22, center_y + 16, 44, 10), 2)
        pygame.draw.rect(surface, color, (center_x - 20, center_y + 18, 40, 6))
        pygame.draw.rect(surface, OUTLINE_COLOR, (center_x - 20, center_y + 18, 40, 6), 2)

class King(Piece):
    def get_possible_moves(self, board) -> List[Tuple[int, int]]:
        moves = []
        row, col = self.pos
        
        # Una casilla en todas direcciones
        for dr in [-1, 0, 1]:
            for dc in [-1, 0, 1]:
                if dr == 0 and dc == 0:
                    continue
                new_row, new_col = row + dr, col + dc
                if 0 <= new_row < 8 and 0 <= new_col < 8:
                    target = board[new_row][new_col]
                    if target is None or target.color != self.color:
                        moves.append((new_row, new_col))
        
        return moves
    
    def draw(self, surface):
        x, y = self.pos[1] * TILE_SIZE, self.pos[0] * TILE_SIZE
        color = WHITE_PIECE if self.color == 'white' else BLACK_PIECE
        shadow_color = (100, 100, 100, 100)
        highlight = (255, 255, 255, 180) if self.color == 'white' else (80, 80, 80)
        center_x, center_y = x + TILE_SIZE // 2, y + TILE_SIZE // 2
        
        # Sombra
        shadow = pygame.Surface((TILE_SIZE, TILE_SIZE), pygame.SRCALPHA)
        pygame.draw.ellipse(shadow, shadow_color, (center_x - x - 24, center_y - y + 25, 48, 12))
        surface.blit(shadow, (x, y))
        
        # Cruz en la corona
        cross_color = (220, 180, 50) if self.color == 'white' else (180, 140, 30)
        # Vertical
        pygame.draw.rect(surface, cross_color, (center_x - 3, center_y - 28, 6, 16))
        pygame.draw.rect(surface, OUTLINE_COLOR, (center_x - 3, center_y - 28, 6, 16), 1)
        # Horizontal
        pygame.draw.rect(surface, cross_color, (center_x - 8, center_y - 23, 16, 6))
        pygame.draw.rect(surface, OUTLINE_COLOR, (center_x - 8, center_y - 23, 16, 6), 1)
        
        # Joya en la cruz
        pygame.draw.circle(surface, (200, 50, 50), (center_x, center_y - 20), 3)
        pygame.draw.circle(surface, OUTLINE_COLOR, (center_x, center_y - 20), 3, 1)
        
        # Corona real con puntas
        for i in range(-16, 20, 8):
            # Puntas de la corona
            peak_points = [
                (center_x + i - 3, center_y - 12),
                (center_x + i, center_y - 18),
                (center_x + i + 3, center_y - 12)
            ]
            pygame.draw.polygon(surface, color, peak_points)
            pygame.draw.polygon(surface, OUTLINE_COLOR, peak_points, 1)
            
            # Esferas decorativas
            pygame.draw.circle(surface, color, (center_x + i, center_y - 18), 4)
            pygame.draw.circle(surface, OUTLINE_COLOR, (center_x + i, center_y - 18), 4, 1)
            pygame.draw.circle(surface, highlight, (center_x + i - 1, center_y - 19), 1)
        
        # Banda de la corona
        pygame.draw.ellipse(surface, color, (center_x - 18, center_y - 14, 36, 10))
        pygame.draw.ellipse(surface, OUTLINE_COLOR, (center_x - 18, center_y - 14, 36, 10), 2)
        
        # Cuerpo del rey (más robusto)
        body_points = [
            (center_x - 14, center_y - 6),
            (center_x + 14, center_y - 6),
            (center_x + 17, center_y + 18),
            (center_x - 17, center_y + 18)
        ]
        pygame.draw.polygon(surface, color, body_points)
        pygame.draw.polygon(surface, OUTLINE_COLOR, body_points, 2)
        
        # Detalles de lujo
        pygame.draw.line(surface, highlight, 
                        (center_x - 10, center_y - 4), 
                        (center_x - 13, center_y + 16), 3)
        
        # Cinturón real
        pygame.draw.rect(surface, cross_color, (center_x - 14, center_y + 4, 28, 4))
        pygame.draw.rect(surface, OUTLINE_COLOR, (center_x - 14, center_y + 4, 28, 4), 1)
        
        # Joya central en el cinturón
        pygame.draw.circle(surface, (50, 100, 200), (center_x, center_y + 6), 3)
        pygame.draw.circle(surface, OUTLINE_COLOR, (center_x, center_y + 6), 3, 1)
        
        # Base real (la más grande)
        pygame.draw.ellipse(surface, color, (center_x - 22, center_y + 16, 44, 10))
        pygame.draw.ellipse(surface, OUTLINE_COLOR, (center_x - 22, center_y + 16, 44, 10), 2)
        pygame.draw.rect(surface, color, (center_x - 20, center_y + 18, 40, 6))
        pygame.draw.rect(surface, OUTLINE_COLOR, (center_x - 20, center_y + 18, 40, 6), 2)

class ChessGame:
    def __init__(self):
        self.board = [[None for _ in range(8)] for _ in range(8)]
        self.current_turn = 'white'
        self.selected_piece = None
        self.possible_moves = []
        self.kings = {'white': None, 'black': None}
        self.game_over = False
        self.winner = None
        self.captured_pieces = {'white': [], 'black': []}
        self.scores = {'white': 0, 'black': 0}
        self.move_history = []
        self.setup_board()
    
    def setup_board(self):
        # Peones
        for i in range(8):
            self.board[1][i] = Pawn('black', (1, i))
            self.board[6][i] = Pawn('white', (6, i))
        
        # Piezas negras
        piece_order = [Rook, Knight, Bishop, Queen, King, Bishop, Knight, Rook]
        for i, piece_class in enumerate(piece_order):
            self.board[0][i] = piece_class('black', (0, i))
            if piece_class == King:
                self.kings['black'] = self.board[0][i]
        
        # Piezas blancas
        for i, piece_class in enumerate(piece_order):
            self.board[7][i] = piece_class('white', (7, i))
            if piece_class == King:
                self.kings['white'] = self.board[7][i]
    
    def is_in_check(self, color: str) -> bool:
        king = self.kings[color]
        if not king:
            return False
        
        king_pos = king.pos
        opponent_color = 'black' if color == 'white' else 'white'
        
        for row in range(8):
            for col in range(8):
                piece = self.board[row][col]
                if piece and piece.color == opponent_color:
                    if king_pos in piece.get_possible_moves(self.board):
                        return True
        return False
    
    def would_be_in_check(self, piece: Piece, new_pos: Tuple[int, int]) -> bool:
        old_pos = piece.pos
        target = self.board[new_pos[0]][new_pos[1]]
        
        # Simular movimiento
        self.board[old_pos[0]][old_pos[1]] = None
        self.board[new_pos[0]][new_pos[1]] = piece
        piece.pos = new_pos
        
        in_check = self.is_in_check(piece.color)
        
        # Revertir
        piece.pos = old_pos
        self.board[old_pos[0]][old_pos[1]] = piece
        self.board[new_pos[0]][new_pos[1]] = target
        
        return in_check
    
    def get_legal_moves(self, piece: Piece) -> List[Tuple[int, int]]:
        possible = piece.get_possible_moves(self.board)
        legal = []
        for move in possible:
            if not self.would_be_in_check(piece, move):
                legal.append(move)
        return legal
    
    def has_legal_moves(self, color: str) -> bool:
        for row in range(8):
            for col in range(8):
                piece = self.board[row][col]
                if piece and piece.color == color:
                    if self.get_legal_moves(piece):
                        return True
        return False
    
    def check_game_over(self):
        if not self.has_legal_moves(self.current_turn):
            self.game_over = True
            if self.is_in_check(self.current_turn):
                self.winner = 'black' if self.current_turn == 'white' else 'white'
            else:
                self.winner = 'draw'
    
    def select_piece(self, pos: Tuple[int, int]):
        row, col = pos
        piece = self.board[row][col]
        
        if self.selected_piece and pos in self.possible_moves:
            self.move_piece(self.selected_piece, pos)
            self.selected_piece = None
            self.possible_moves = []
        elif piece and piece.color == self.current_turn:
            self.selected_piece = piece
            self.possible_moves = self.get_legal_moves(piece)
        else:
            self.selected_piece = None
            self.possible_moves = []
    
    def move_piece(self, piece: Piece, new_pos: Tuple[int, int]):
        old_pos = piece.pos
        
        # Captura de pieza
        target = self.board[new_pos[0]][new_pos[1]]
        if target:
            if isinstance(target, King):
                self.game_over = True
                self.winner = piece.color
            else:
                # Añadir pieza capturada y sumar puntos
                self.captured_pieces[piece.color].append(target)
                self.scores[piece.color] += target.get_value()
        
        self.board[old_pos[0]][old_pos[1]] = None
        self.board[new_pos[0]][new_pos[1]] = piece
        piece.pos = new_pos
        piece.has_moved = True
        
        # Promoción de peón
        if isinstance(piece, Pawn):
            if (piece.color == 'white' and new_pos[0] == 0) or \
               (piece.color == 'black' and new_pos[0] == 7):
                new_queen = Queen(piece.color, new_pos)
                self.board[new_pos[0]][new_pos[1]] = new_queen
                piece = new_queen
        
        # Registrar movimiento
        self.move_history.append((old_pos, new_pos, piece.__class__.__name__))
        
        self.current_turn = 'black' if self.current_turn == 'white' else 'white'
        self.check_game_over()
    
    def draw_board(self, surface):
        # Borde del tablero
        pygame.draw.rect(surface, BOARD_BORDER, (0, 0, BOARD_WIDTH, HEIGHT), 5)
        
        for row in range(BOARD_SIZE):
            for col in range(BOARD_SIZE):
                color = LIGHT_SQUARE if (row + col) % 2 == 0 else DARK_SQUARE
                pygame.draw.rect(surface, color, (col * TILE_SIZE, row * TILE_SIZE, TILE_SIZE, TILE_SIZE))
        
        # Destacar casilla seleccionada
        if self.selected_piece:
            row, col = self.selected_piece.pos
            s = pygame.Surface((TILE_SIZE, TILE_SIZE), pygame.SRCALPHA)
            s.fill(SELECTED_COLOR)
            surface.blit(s, (col * TILE_SIZE, row * TILE_SIZE))
        
        # Destacar movimientos posibles
        for move in self.possible_moves:
            row, col = move
            s = pygame.Surface((TILE_SIZE, TILE_SIZE), pygame.SRCALPHA)
            s.fill(HIGHLIGHT_COLOR)
            surface.blit(s, (col * TILE_SIZE, row * TILE_SIZE))
            
            # Círculo para casilla vacía, anillo para captura
            if self.board[row][col] is None:
                pygame.draw.circle(surface, (90, 90, 90, 180), 
                                 (col * TILE_SIZE + TILE_SIZE // 2, row * TILE_SIZE + TILE_SIZE // 2), 12)
            else:
                pygame.draw.circle(surface, (200, 60, 60, 200), 
                                 (col * TILE_SIZE + TILE_SIZE // 2, row * TILE_SIZE + TILE_SIZE // 2), 
                                 TILE_SIZE // 2 - 5, 4)
        
        # Destacar jaque
        if self.is_in_check(self.current_turn):
            king = self.kings[self.current_turn]
            if king:
                row, col = king.pos
                s = pygame.Surface((TILE_SIZE, TILE_SIZE), pygame.SRCALPHA)
                s.fill(CHECK_COLOR)
                surface.blit(s, (col * TILE_SIZE, row * TILE_SIZE))
    
    def draw_pieces(self, surface):
        for row in range(8):
            for col in range(8):
                piece = self.board[row][col]
                if piece:
                    piece.draw(surface)
    
    def draw_ui(self, surface):
        # Panel lateral
        sidebar_rect = pygame.Rect(BOARD_WIDTH, 0, SIDEBAR_WIDTH, HEIGHT)
        pygame.draw.rect(surface, SIDEBAR_BG, sidebar_rect)
        pygame.draw.line(surface, BOARD_BORDER, (BOARD_WIDTH, 0), (BOARD_WIDTH, HEIGHT), 3)
        
        font_title = pygame.font.Font(None, 42)
        font_normal = pygame.font.Font(None, 32)
        font_small = pygame.font.Font(None, 24)
        
        y_offset = 30
        
        # Título
        title = font_title.render('AJEDREZ', True, TEXT_COLOR)
        surface.blit(title, (BOARD_WIDTH + (SIDEBAR_WIDTH - title.get_width()) // 2, y_offset))
        y_offset += 60
        
        # Línea separadora
        pygame.draw.line(surface, ACCENT_COLOR, 
                        (BOARD_WIDTH + 20, y_offset), 
                        (BOARD_WIDTH + SIDEBAR_WIDTH - 20, y_offset), 2)
        y_offset += 30
        
        if self.game_over:
            if self.winner == 'draw':
                status = font_normal.render('¡EMPATE!', True, (241, 196, 15))
                surface.blit(status, (BOARD_WIDTH + (SIDEBAR_WIDTH - status.get_width()) // 2, y_offset))
            else:
                winner_text = 'BLANCAS' if self.winner == 'white' else 'NEGRAS'
                status = font_normal.render('¡GANADOR!', True, WIN_COLOR)
                winner = font_normal.render(winner_text, True, WIN_COLOR)
                surface.blit(status, (BOARD_WIDTH + (SIDEBAR_WIDTH - status.get_width()) // 2, y_offset))
                surface.blit(winner, (BOARD_WIDTH + (SIDEBAR_WIDTH - winner.get_width()) // 2, y_offset + 40))
            y_offset += 100
            
            restart = font_small.render('Presiona R', True, TEXT_COLOR)
            restart2 = font_small.render('para reiniciar', True, TEXT_COLOR)
            surface.blit(restart, (BOARD_WIDTH + (SIDEBAR_WIDTH - restart.get_width()) // 2, y_offset))
            surface.blit(restart2, (BOARD_WIDTH + (SIDEBAR_WIDTH - restart2.get_width()) // 2, y_offset + 25))
        else:
            # Turno actual
            turn_text = 'BLANCAS' if self.current_turn == 'white' else 'NEGRAS'
            turn_label = font_small.render('Turno:', True, TEXT_COLOR)
            turn_value = font_normal.render(turn_text, True, ACCENT_COLOR)
            surface.blit(turn_label, (BOARD_WIDTH + (SIDEBAR_WIDTH - turn_label.get_width()) // 2, y_offset))
            surface.blit(turn_value, (BOARD_WIDTH + (SIDEBAR_WIDTH - turn_value.get_width()) // 2, y_offset + 25))
            y_offset += 80
            
            if self.is_in_check(self.current_turn):
                check_text = font_normal.render('¡JAQUE!', True, CHECK_COLOR)
                surface.blit(check_text, (BOARD_WIDTH + (SIDEBAR_WIDTH - check_text.get_width()) // 2, y_offset))
                y_offset += 50
        
        # Línea separadora
        pygame.draw.line(surface, ACCENT_COLOR, 
                        (BOARD_WIDTH + 20, y_offset), 
                        (BOARD_WIDTH + SIDEBAR_WIDTH - 20, y_offset), 2)
        y_offset += 30
        
        # Puntuación
        score_title = font_normal.render('PUNTUACIÓN', True, TEXT_COLOR)
        surface.blit(score_title, (BOARD_WIDTH + (SIDEBAR_WIDTH - score_title.get_width()) // 2, y_offset))
        y_offset += 45
        
        # Ventaja de material
        score_diff = self.scores['white'] - self.scores['black']
        
        white_score = font_normal.render(f'Blancas: {self.scores["white"]}', True, TEXT_COLOR)
        surface.blit(white_score, (BOARD_WIDTH + 20, y_offset))
        if score_diff > 0:
            advantage = font_small.render(f'+{score_diff}', True, WIN_COLOR)
            surface.blit(advantage, (BOARD_WIDTH + SIDEBAR_WIDTH - 50, y_offset + 5))
        y_offset += 40
        
        black_score = font_normal.render(f'Negras: {self.scores["black"]}', True, TEXT_COLOR)
        surface.blit(black_score, (BOARD_WIDTH + 20, y_offset))
        if score_diff < 0:
            advantage = font_small.render(f'+{abs(score_diff)}', True, WIN_COLOR)
            surface.blit(advantage, (BOARD_WIDTH + SIDEBAR_WIDTH - 50, y_offset + 5))
        y_offset += 50
        
        # Línea separadora
        pygame.draw.line(surface, ACCENT_COLOR, 
                        (BOARD_WIDTH + 20, y_offset), 
                        (BOARD_WIDTH + SIDEBAR_WIDTH - 20, y_offset), 2)
        y_offset += 25
        
        # Piezas capturadas
        capture_title = font_small.render('PIEZAS CAPTURADAS', True, TEXT_COLOR)
        surface.blit(capture_title, (BOARD_WIDTH + (SIDEBAR_WIDTH - capture_title.get_width()) // 2, y_offset))
        y_offset += 35
        
        # Piezas capturadas por blancas (piezas negras)
        white_captures = font_small.render('Por Blancas:', True, TEXT_COLOR)
        surface.blit(white_captures, (BOARD_WIDTH + 20, y_offset))
        y_offset += 25
        
        self.draw_captured_pieces(surface, 'white', BOARD_WIDTH + 20, y_offset)
        y_offset += 80
        
        # Piezas capturadas por negras (piezas blancas)
        black_captures = font_small.render('Por Negras:', True, TEXT_COLOR)
        surface.blit(black_captures, (BOARD_WIDTH + 20, y_offset))
        y_offset += 25
        
        self.draw_captured_pieces(surface, 'black', BOARD_WIDTH + 20, y_offset)
    
    def draw_captured_pieces(self, surface, capturing_color: str, x: int, y: int):
        """Dibuja las piezas capturadas en miniatura"""
        pieces = self.captured_pieces[capturing_color]
        
        piece_icons = {
            'Pawn': '♟', 'Knight': '♞', 'Bishop': '♝', 
            'Rook': '♜', 'Queen': '♛', 'King': '♚'
        }
        
        font = pygame.font.Font(None, 32)
        offset_x = 0
        offset_y = 0
        
        for i, piece in enumerate(pieces):
            piece_name = piece.__class__.__name__
            icon = piece_icons.get(piece_name, '?')
            
            # Color de la pieza capturada (opuesto al que captura)
            color = BLACK_PIECE if piece.color == 'black' else WHITE_PIECE
            
            # Renderizar ícono
            text = font.render(icon, True, color)
            surface.blit(text, (x + offset_x, y + offset_y))
            
            offset_x += 35
            if offset_x > 180:
                offset_x = 0
                offset_y += 35

def main():
    game = ChessGame()
    
    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()
            
            if event.type == pygame.MOUSEBUTTONDOWN:
                if not game.game_over:
                    mouse_pos = pygame.mouse.get_pos()
                    col = mouse_pos[0] // TILE_SIZE
                    row = mouse_pos[1] // TILE_SIZE
                    if 0 <= row < 8 and 0 <= col < 8:
                        game.select_piece((row, col))
            
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_r:
                    game = ChessGame()
        
        screen.fill(SIDEBAR_BG)
        game.draw_board(screen)
        game.draw_pieces(screen)
        game.draw_ui(screen)
        
        pygame.display.flip()
        clock.tick(60)

if __name__ == '__main__':
    main()