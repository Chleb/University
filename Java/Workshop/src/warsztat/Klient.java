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
public class Klient {
    private int id;
    private String imie;
    private String nazwisko;
    private String telnum;
    private String miejscowosc;
    private String ulica;
    private String email;
    private Auto[] auta;
    
    public Klient(String imie,String nazwisko,String telnum,String miejscowosc,String ulica,String email)
    {
        this.email = email;
        this.imie = imie;
        this.miejscowosc = miejscowosc;
        this.nazwisko = nazwisko;
        this.telnum = telnum;
        this.ulica = ulica;
    }
    
    public Klient(int id,String imie,String nazwisko,String telnum,String miejscowosc,String ulica,String email)
    {
        this.id = id;
        this.email = email;
        this.imie = imie;
        this.miejscowosc = miejscowosc;
        this.nazwisko = nazwisko;
        this.telnum = telnum;
        this.ulica = ulica;
    }
    
    public String getImie(){return imie;};
    public String getNazwisko(){return nazwisko;};
    public String getTelnum(){return telnum;};
    public String getMiejsc(){return miejscowosc;};
    public String getUlica(){return ulica;};
    public String getEmail(){return email;};
    public int getId(){return id;}
    
    public void setImie(String imie){this.imie = imie;};
    public void setNazwisko(String nazwisko){this.nazwisko = nazwisko;};
    public void setTelnum(String tel){telnum = tel;};
    public void setMiejsc(String miejsc){miejscowosc = miejsc;};
    public void setUlica(String ulica){this.ulica = ulica;};
    public void setEmail(String email){this.email = email;};
}
