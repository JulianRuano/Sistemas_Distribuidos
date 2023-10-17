package susuario.dto;

import java.io.Serializable;

public class UsuarioDTO implements Serializable {
    private int ID;
    private String nombres;
    private String nombreUsuario;
    private String clave;

    public UsuarioDTO(int id, String nombres, String nombreUsuario, String clave) {
        this.ID = id;
        this.nombres = nombres;
        this.nombreUsuario = nombreUsuario;
        this.clave = clave;
    }

    public UsuarioDTO() {
        this.ID = 0;
        this.nombres = "";
        this.nombreUsuario = "";
        this.clave = "";
    }

    public int getID() {
        return ID;
    }

    public void setID(int ID) {
        this.ID = ID;
    }

    public String getNombres() {
        return nombres;
    }

    public void setNombres(String nombres) {
        this.nombres = nombres;
    }

    public void setNombreUsuario(String nombreUsuario) {
        this.nombreUsuario = nombreUsuario;
    }

    public String getNombreUsuario() {
        return this.nombreUsuario;
    }

    public void setClave(String clave) {
        this.clave = clave;
    }

    public String getClave() {
        return this.clave;
    }

}
