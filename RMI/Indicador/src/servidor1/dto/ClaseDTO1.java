package servidor1.dto;

import java.io.Serializable;

/**
 *
 * @author Lenovo!
 */
public class ClaseDTO1 implements Serializable{
    private int id;
    private int indicador;

    public ClaseDTO1(int id,int indicador) {
        this.id = id;
        this.indicador = indicador;
    }

    public int getId() {
        return id;
    }
    public void setId(int id) {
        this.id = id;
    }
    public int getIndicador() {
        return this.indicador;
    }
    public void setIndicador(int indicador) {
        this.indicador = indicador;
    }
}
