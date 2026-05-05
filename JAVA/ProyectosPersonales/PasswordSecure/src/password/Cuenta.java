package password;
public class Cuenta {

    private String usuario;
    private String contrasena;
    private String url;
    private int longitud;

    public Cuenta(String usuario, String contrasena, String url) {
        this.usuario = usuario;
        this.contrasena = contrasena;
        this.url = url;
        this.longitud = contrasena.length();
    }

    public Cuenta(String usuario, String contrasena) {
        this.usuario = usuario;
        this.contrasena = contrasena;
        this.url = "";
        this.longitud = contrasena.length();
    }

    public Cuenta(String usuario, int tamaño) {
        this.usuario = usuario;

        PasswordGenerator generator = new PasswordGenerator();
        this.contrasena = generator.doPasswordSecure(tamaño);

        this.url = "";
        this.longitud = this.contrasena.length();
    }

    public String getUsuario() {
        return usuario;
    }
    public String getUrl() {
        return url;
    }
    public int getLongitud() {
        return longitud;
    }


    public void setUsuario(String usuario) {
        this.usuario = usuario;
    }
    public void setContrasena(String contrasena) {
        this.contrasena = contrasena;
        this.longitud = contrasena.length();
    }

    public void mostrarCuenta() {
        System.out.println("| " + url + " |");
        System.out.println("| " + usuario + " |");
        System.out.println("| " + contrasena + " |");
        System.out.println("| Longitud: " + longitud + " |");
        System.out.println("----------------------");
    }
}