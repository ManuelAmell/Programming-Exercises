// ------------------------------------------------
// CREAR TU PROPIA EXCEPCIÓN
// Útil para errores específicos de tu lógica de negocio.
// ------------------------------------------------
class SaldoInsuficienteException extends Exception {
    public SaldoInsuficienteException(double saldo, double monto) {
        super("Saldo insuficiente. Saldo: $" + saldo + " | Monto pedido: $" + monto);
    }
}

class CuentaBancaria {
    private double saldo;

    public CuentaBancaria(double saldo) {
        this.saldo = saldo;
    }

    // "throws" avisa que este método puede lanzar esa excepción
    public void retirar(double monto) throws SaldoInsuficienteException {
        if (monto > saldo) {
            throw new SaldoInsuficienteException(saldo, monto);
        }
        saldo -= monto;
        System.out.println("Retiro exitoso. Saldo restante: $" + saldo);
    }
}

public class ExcepcionesPersonalizadas {
    public static void main(String[] args) {

        CuentaBancaria cuenta = new CuentaBancaria(100.0);

        try {
            cuenta.retirar(50.0);  // funciona
            cuenta.retirar(200.0); // lanza la excepción
        } catch (SaldoInsuficienteException e) {
            System.out.println("Error de negocio: " + e.getMessage());
        } finally {
            // finally SIEMPRE se ejecuta, haya error o no.
            // Útil para cerrar conexiones, archivos, etc.
            System.out.println("Operación terminada.");
        }
    }
}