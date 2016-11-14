/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package warsztat;

/**
 *
 * @author Karol
 */
public class Auto {
    private int id,klientId;
    private String marka;
    private String model;
    private String rejestracja;
    private int rokProd;
    
    public Auto(String marka,String model, String rejestracja, int rokProd, int klientId)
    {
        this.marka = marka;
        this.model = model;
        this.rejestracja = rejestracja;
        this.rokProd = rokProd;
        this.klientId = klientId;
    }
    
    public Auto(int id,String marka,String model, String rejestracja, int rokProd, int klientId)
    {
        this.id = id;
        this.marka = marka;
        this.model = model;
        this.rejestracja = rejestracja;
        this.rokProd = rokProd;
        this.klientId = klientId;
    }
    
    public String getMarka(){return marka;};
    public String getModel(){return model;};
    public String getRej(){return rejestracja;};
    public int getRok(){return rokProd;};
    public int getKlient(){return klientId;};
    public int getId(){return id;};
    
    public void setMarka(String marka){this.marka = marka;};
    public void setModel(String model){this.model = model;};
    public void setRok(int rok){rokProd = rok;};
    public void setRej(String rej){rejestracja = rej;};
}
