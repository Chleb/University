package warsztat;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.sql.Timestamp;
import java.util.logging.Level;
import java.util.logging.Logger;

public abstract class DataControl {    
    private static Connection con;
    static int connectionType;
    public static void Connect(String name, String login, String password) throws SQLException
    {
        con = DriverManager.getConnection("jdbc:postgresql://localhost:5432/warsztat","admin","test");
    }
    
    public static void NowyKlient(Klient nowy) throws SQLException
    {
        String stm = "INSERT INTO klient(imie, nazwisko,email,numer_telefonu,miejscowosc,ulica) VALUES(?, ?, ?, ?, ?, ?)";
        PreparedStatement pst = con.prepareStatement(stm);
        pst.setString(1, nowy.getImie());
        pst.setString(2, nowy.getNazwisko());
        pst.setString(3, nowy.getEmail());
        pst.setString(4, nowy.getTelnum());
        pst.setString(5, nowy.getMiejsc());
        pst.setString(6, nowy.getUlica());
        pst.executeUpdate();
    }
    
    public static void NoweAuto(Auto nowe) throws SQLException
    {
        String stm = "INSERT INTO auto(marka,model,rok_produkcji,rejestracja,posiadacz_id) VALUES(?, ?, ?, ?, ?)";
        PreparedStatement pst = con.prepareStatement(stm);
        pst.setString(1, nowe.getMarka());
        pst.setString(2, nowe.getModel());
        pst.setInt(3, nowe.getRok());
        pst.setString(4, nowe.getRej());
        pst.setInt(5, nowe.getKlient());
        pst.executeUpdate();
    }
    
    
    public static Klient[] Klienci() throws SQLException
    {
        con.setAutoCommit(false);
        PreparedStatement pst = con.prepareStatement("SELECT count(*) FROM klient");
        ResultSet rs = pst.executeQuery();
        rs.next();
        int n = rs.getInt(1);
        Klient[] lista = new Klient[n];
        pst = con.prepareStatement("SELECT * FROM klient");
        rs = pst.executeQuery();
        con.commit();
        con.setAutoCommit(true);
        int i = 0;
        while(rs.next())
        {
            lista[i] = new Klient(rs.getInt(1),rs.getString(2),rs.getString(3),rs.getString(5),rs.getString(6),rs.getString(7),rs.getString(4));
            i++;
        }
        return lista;
    }
    
    public static Auto[] Auta(int id) throws SQLException
    {
        con.setAutoCommit(false);
        PreparedStatement pst = con.prepareStatement("SELECT count(*) FROM auto WHERE posiadacz_id =" + id);
        ResultSet rs = pst.executeQuery();
        rs.next();
        int n = rs.getInt(1);
        Auto[] lista = new Auto[n];
        pst = con.prepareStatement("SELECT * FROM auto WHERE posiadacz_id =" + id);
        rs = pst.executeQuery();
        con.commit();
        con.setAutoCommit(true);
        int i = 0;
        while(rs.next())
        {
            lista[i] = new Auto(rs.getInt(1),rs.getString(2),rs.getString(3),rs.getString(6),rs.getInt(4),rs.getInt(5));
            i++;
        }
        return lista;
    }
    
    public static void UpdKlient(Klient nowy) throws SQLException
    {
        PreparedStatement pst = con.prepareStatement("UPDATE klient SET imie = ?, nazwisko = ?, email = ?, numer_telefonu = ?, miejscowosc = ?, ulica = ? WHERE klient_id = ?");
        pst.setString(1, nowy.getImie());
        pst.setString(2, nowy.getNazwisko());
        pst.setString(3, nowy.getEmail());
        pst.setString(4, nowy.getTelnum());
        pst.setString(5, nowy.getMiejsc());
        pst.setString(6, nowy.getUlica());
        pst.setInt(7, nowy.getId());
        pst.executeUpdate();
    }
    
    public static void UpdAuto(Auto nowe) throws SQLException
    {
        PreparedStatement pst = con.prepareStatement("UPDATE auto SET model = ?, marka = ?, rok_produkcji = ?, rejestracja = ? WHERE auto_id = ?");
        pst.setString(1, nowe.getModel());
        pst.setString(2, nowe.getMarka());
        pst.setInt(3, nowe.getRok());
        pst.setString(4, nowe.getRej());
        pst.setInt(5, nowe.getId());
        pst.executeUpdate();
    }
    
    
    public static void DelCar(int id) throws SQLException
    {
        PreparedStatement pst = con.prepareStatement("DELETE FROM auto WHERE auto_id = "+ id);
        pst.executeUpdate();
    }
    
    public static Zgloszenie[] wolneZgl() throws SQLException
    {
        con.setAutoCommit(false);
        PreparedStatement pst = con.prepareStatement("SELECT count(*) FROM zgloszenia_clas WHERE data_przyjecia IS NULL");
        ResultSet rs = pst.executeQuery();
        rs.next();
        int n = rs.getInt(1);
        pst = con.prepareStatement("SELECT * FROM zgloszenia_clas WHERE data_przyjecia IS NULL");
        rs = pst.executeQuery();
        con.commit();
        con.setAutoCommit(true);
        Zgloszenie[] lista = new Zgloszenie[n];
        int i = 0;
        while(rs.next())
        {
            lista[i] = new Zgloszenie();
            lista[i].opis = rs.getString("opis");
            lista[i].id = rs.getInt("zgloszenie_id");
            lista[i].naprawa_id = rs.getInt("naprawa_id");
            lista[i].auto = rs.getString("marka") + " " + rs.getString("model");
            lista[i].klient = rs.getString("imie") + " " + rs.getString("nazwisko");
            lista[i].telnum = rs.getString("numer_telefonu");
            lista[i].data1 = rs.getTimestamp("data_zgloszenia").toString().substring(0, 10);
            i++;
        }
        return lista;
    }
    public static Zgloszenie[] aktywneZgl() throws SQLException
    {
        con.setAutoCommit(false);
        PreparedStatement pst = con.prepareStatement("SELECT count(*) FROM zgloszenia_clas WHERE data_przyjecia IS NOT NULL AND data_zakonczenia IS NULL");
        ResultSet rs = pst.executeQuery();
        rs.next();
        int n = rs.getInt(1);
        pst = con.prepareStatement("SELECT * FROM zgloszenia_clas WHERE data_przyjecia IS NOT NULL AND data_zakonczenia IS NULL");
        rs = pst.executeQuery();
        con.commit();
        con.setAutoCommit(true);
        Zgloszenie[] lista = new Zgloszenie[n];
        int i = 0;
        while(rs.next())
        {
            lista[i] = new Zgloszenie();
            lista[i].opis = rs.getString("opis");
            lista[i].id = rs.getInt("zgloszenie_id");
            lista[i].naprawa_id = rs.getInt("naprawa_id");
            lista[i].auto = rs.getString("marka") + " " + rs.getString("model");
            lista[i].klient = rs.getString("imie") + " " + rs.getString("nazwisko");
            lista[i].telnum = rs.getString("numer_telefonu");
            lista[i].data1 = rs.getTimestamp("data_zgloszenia").toString().substring(0, 10);
            lista[i].data2 = rs.getTimestamp("data_przyjecia").toString().substring(0, 10);
            i++;
        }
        return lista;
    }
    
    public static Zgloszenie[] zakonczoneZgl() throws SQLException
    {
        con.setAutoCommit(false);
        PreparedStatement pst = con.prepareStatement("SELECT count(*) FROM zgloszenia_clas WHERE data_przyjecia IS NOT NULL AND data_zakonczenia IS NOT NULL");
        ResultSet rs = pst.executeQuery();
        rs.next();
        int n = rs.getInt(1);
        pst = con.prepareStatement("SELECT * FROM zgloszenia_clas WHERE data_przyjecia IS NOT NULL AND data_zakonczenia IS NOT NULL");
        rs = pst.executeQuery();
        con.commit();
        con.setAutoCommit(true);
        Zgloszenie[] lista = new Zgloszenie[n];
        int i = 0;
        while(rs.next())
        {
            lista[i] = new Zgloszenie();
            lista[i].opis = rs.getString("opis");
            lista[i].id = rs.getInt("zgloszenie_id");
            lista[i].naprawa_id = rs.getInt("naprawa_id");
            lista[i].auto = rs.getString("marka") + " " + rs.getString("model");
            lista[i].klient = rs.getString("imie") + " " + rs.getString("nazwisko");
            lista[i].telnum = rs.getString("numer_telefonu");
            lista[i].data1 = rs.getTimestamp("data_zgloszenia").toString().substring(0, 10);
            lista[i].data2 = rs.getTimestamp("data_przyjecia").toString().substring(0, 10);
            lista[i].data3 = rs.getTimestamp("data_zakonczenia").toString().substring(0, 10);
            i++;
        }
        return lista;
    }

    static void NoweZgloszenie(int id, int id0, String text) throws SQLException {
        PreparedStatement pst = con.prepareStatement("INSERT INTO zgloszenie(opis,zglaszajacy_id,zgl_auto_id,data_zgloszenia) VALUES(?," + id + ", " + id0 + ", current_timestamp)");
        pst.setString(1, text);
        pst.executeUpdate();
    }

    static void UpdZgl(int id, String text) throws SQLException {
        PreparedStatement pst = con.prepareStatement("UPDATE zgloszenie SET opis = ? WHERE zgloszenie_id = " + id);
        pst.setString(1,text);
        pst.executeUpdate();
    }

    static void DelZglo(int id) throws SQLException {
        PreparedStatement pst = con.prepareStatement("DELETE FROM zgloszenie WHERE zgloszenie_id = " + id);
        pst.executeUpdate();
    }

    static void DelKlient(int id) throws SQLException {
        PreparedStatement pst = con.prepareStatement("DELETE FROM klient WHERE klient_id = " + id);
        pst.executeUpdate();
    }

    static void NowaNaprawa(int parseInt, int id) throws SQLException {
        PreparedStatement pst = con.prepareStatement("INSERT INTO naprawa(koszt,notify_id,data_przyjecia) VALUES(" + parseInt + ", " + id + ", current_timestamp)");
        pst.executeUpdate();
    }
    
    static Naprawa[] aktywneNaprawy() throws SQLException
    {
        con.setAutoCommit(false);
        PreparedStatement pst = con.prepareStatement("SELECT count(*) FROM naprawa WHERE data_zakonczenia IS NULL");
        ResultSet rs = pst.executeQuery();
        rs.next();
        int n = rs.getInt(1);
        Naprawa[] lista = new Naprawa[n];
        pst = con.prepareStatement("SELECT naprawa_id,opis,marka,model FROM naprawa JOIN zgloszenie ON(notify_id = zgloszenie_id) JOIN auto ON(zgl_auto_id = auto_id) WHERE data_zakonczenia IS NULL");
        rs = pst.executeQuery();
        con.commit();
        con.setAutoCommit(true);
        int i = 0;
        while(rs.next())
        {
            lista[i] = new Naprawa();
            lista[i].id = rs.getInt(1);
            lista[i].opis = rs.getString(2);
            lista[i].marka = rs.getString(3);
            lista[i].model = rs.getString(4);
            i++;
        }
        return lista;
    }

    static Czesc_zamienna[] WszCzesci() throws SQLException
    {
        con.setAutoCommit(false);
        PreparedStatement pst = con.prepareStatement("SELECT count(*) FROM czesc_zamienna");
        ResultSet rs = pst.executeQuery();
        rs.next();
        int n = rs.getInt(1);
        Czesc_zamienna[] lista = new Czesc_zamienna[n];
        pst = con.prepareStatement("SELECT czesc_id,nazwa,model,liczba FROM czesc_zamienna");
        rs = pst.executeQuery();
        con.commit();
        con.setAutoCommit(true);
        int i = 0;
        while(rs.next())
        {
            lista[i] = new Czesc_zamienna();
            lista[i].id = rs.getInt(1);
            lista[i].ilosc = rs.getInt(4);
            lista[i].model = rs.getString(3);
            lista[i].nazwa = rs.getString(2);
            i++;
        }
        return lista;
    }
    
    
    static Czesc_zamienna[] czesciZam(int id) throws SQLException {
        con.setAutoCommit(false);
        PreparedStatement pst = con.prepareStatement("SELECT count(*) FROM czesc_naprawa WHERE napr_id = " + id);
        ResultSet rs = pst.executeQuery();
        rs.next();
        int n = rs.getInt(1);
        Czesc_zamienna[] lista = new Czesc_zamienna[n];
        pst = con.prepareStatement("SELECT czesc_naprawa.czesc_id,nazwa,model,ilosc FROM czesc_naprawa JOIN czesc_zamienna USING(czesc_id) WHERE napr_id = " + id);
        rs = pst.executeQuery();
        con.commit();
        con.setAutoCommit(true);
        int i = 0;
        while(rs.next())
        {
            lista[i] = new Czesc_zamienna();
            lista[i].id = rs.getInt(1);
            lista[i].ilosc = rs.getInt(4);
            lista[i].model = rs.getString(3);
            lista[i].nazwa = rs.getString(2);
            i++;
        }
        return lista;
    }
    
    static void DodajCzesc(int id_czesci,int id_naprawy,int ilosc) throws SQLException
    {
            con.setAutoCommit(false);
            int n = ilosc;
            PreparedStatement pst = con.prepareStatement("SELECT ilosc FROM czesc_naprawa WHERE czesc_id = " + id_czesci + " AND napr_id = " + id_naprawy);
            ResultSet rs = pst.executeQuery();
            if(rs.next())
                n += rs.getInt(1);
            pst = con.prepareStatement("DELETE FROM czesc_naprawa WHERE czesc_id = " + id_czesci + " AND napr_id = " + id_naprawy);
            pst.executeUpdate();
            pst = con.prepareStatement("INSERT INTO czesc_naprawa(czesc_id,napr_id,ilosc) VALUES(" + id_czesci + ", " + id_naprawy + ", " + n + ")");
            pst.executeUpdate();
            con.commit();
            con.setAutoCommit(true);
    }
    
    static void ZakonczNapr(int id) throws SQLException
    {
        PreparedStatement pst = con.prepareStatement("UPDATE naprawa SET data_zakonczenia = current_timestamp WHERE naprawa_id = " + id);
        pst.executeUpdate();
    }
}
