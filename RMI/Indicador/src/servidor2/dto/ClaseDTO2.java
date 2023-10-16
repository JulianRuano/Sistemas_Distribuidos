/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package servidor2.dto;

import java.io.Serializable;

public class ClaseDTO2 implements Serializable{
    private int id;
    private int alerta;

    public ClaseDTO2(int id, int alerta) {
        this.id = id;
        this.alerta = alerta;
    }

    public int getId() {
        return id;
    }
    public void setId(int id) {
        this.id = id;
    }
    public float getAlerta() {
        return this.alerta;
    }
    public void setAlerta(int alerta) {
        this.alerta = alerta;
    }
}
