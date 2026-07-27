import sympy as sp


def resolver_indefinida():
    try:
        expr_str = input("Función f(x): ")
        var_str = input("Variable: ")
        var = sp.Symbol(var_str)
        expr = sp.sympify(expr_str)
        F = sp.integrate(expr, var)
        print("\nResultado:")
        print(sp.pretty(F, use_unicode=True) + " + C\n")
    except Exception as e:
        print(f"Error: {e}\n")
        print("""
                 === FORMATO DE ENTRADA ===
                Use sintaxis de Python/SymPy:
                Multiplicación:  2*x
                Potencias:       x**2
                División:        1/x
                Raíces:          sqrt(x)
                Trigonométricas: sin(x), cos(x), tan(x)
                Logaritmo:       log(x)
                Exponencial:     exp(x)

                    Ejemplos:
                        x**2 + 3*x + 1
                        sin(x)*cos(x)
                        1/(x+1)
                        sqrt(x)= equivalente a x**(1/2)
                        24*x**9
                        exp(x)
                            """)


def resolver_definida():
    try:
        expr_str = input("Función f(x): ")
        var_str = input("Variable: ")
        var = sp.Symbol(var_str)
        expr = sp.sympify(expr_str)
        a = input("Límite inferior: ")
        b = input("Límite superior: ")
        a = sp.sympify(a)
        b = sp.sympify(b)
        F = sp.integrate(expr, (var, a, b))
        print("\nResultado:")
        sp.pprint(F, use_unicode=True)
        print()
    except Exception as e:
        print(f"Error: {e}\n")
        print("""
                 === FORMATO DE ENTRADA ===
                Use sintaxis de Python/SymPy:
                Multiplicación:  2*x
                Potencias:       x**2
                División:        1/x
                Raíces:          sqrt(x)
                Trigonométricas: sin(x), cos(x), tan(x)
                Logaritmo:       log(x)
                Exponencial:     exp(x)

                    Ejemplos:
                        x**2 + 3*x + 1
                        sin(x)*cos(x)
                        1/(x+1)
                        sqrt(x)= equivalente a x**(1/2)
                        24*x**9
                        exp(x)
                            """)


def main():
    while True:
        print("=== CALCULADORA DE INTEGRALES ===")
        print("1. Integral indefinida")
        print("2. Integral definida")
        print("3. Salir")
        opcion = input("Elige: ").strip()

        if opcion == "1":
            resolver_indefinida()
        elif opcion == "2":
            resolver_definida()
        elif opcion == "3":
            print("¡Hasta luego profesor!")
            break
        else:
            print("Opción inválida.\n")


if __name__ == "__main__":
    main()
