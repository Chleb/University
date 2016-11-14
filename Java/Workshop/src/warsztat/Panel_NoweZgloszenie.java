/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package warsztat;

import java.sql.SQLException;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Karol
 */
public class Panel_NoweZgloszenie extends javax.swing.JDialog {

    Klient[] klienci;
    Klient selKlient;
    Auto[] auta;
    Auto selAuto;
    Panel_Zgloszenia x;
    
    public Panel_NoweZgloszenie(java.awt.Frame parent, boolean modal, Panel_Zgloszenia x) {
        super(parent, modal);
        initComponents();
        this.x = x;
        reset();
    }

    public void reset()
    {
        try {
            SWTel1.setText("");
            SWTel2.setText("");
            SWTel3.setText("");
            SWRejestr.setText("");
            SWRokProd.setText("");
            SWKlienciLista.removeAllItems();
            SWAutaKlientaLista.removeAllItems();
            klienci = DataControl.Klienci();
            for(int i = 0; i < klienci.length ; i++)
            {
                SWKlienciLista.addItem(klienci[i].getImie() + " " + klienci[i].getNazwisko());
            }
            if(klienci.length > 0)
                selKlient = klienci[0];
            resetText1();
        } catch (SQLException ex) {
            Logger.getLogger(Panel_NoweZgloszenie.class.getName()).log(Level.SEVERE, null, ex);
        }
        
    }
    
    public void resetText1()
    {
        if(selKlient != null)
        {
            try {
                SWTel1.setText(selKlient.getTelnum().substring(0, 3));
                SWTel2.setText(selKlient.getTelnum().substring(4, 7));
                SWTel3.setText(selKlient.getTelnum().substring(8, 11));
                SWAutaKlientaLista.removeAllItems();
                auta = DataControl.Auta(selKlient.getId());
                for(int i = 0; i < auta.length; i++)
                {
                    SWAutaKlientaLista.addItem(auta[i].getMarka() + " " + auta[i].getModel());
                }
                if(auta.length > 0)
                    selAuto = auta[0];
                else
                    selAuto = null;
            } catch (SQLException ex) {
                Logger.getLogger(Panel_NoweZgloszenie.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
        else
        {
            SWTel1.setText("");
            SWTel2.setText("");
            SWTel3.setText("");
            SWAutaKlientaLista.removeAllItems();
            auta = null;
            selAuto = null;
        }
        resetText2();
    }
    
    public void resetText2()
    {
        if(selAuto != null)
        {
            SWRejestr.setText(selAuto.getRej());
            SWRokProd.setText(selAuto.getRok() + "");
        }
        else
        {
            SWRejestr.setText("");
            SWRokProd.setText("");
        }
    }
    
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jPanel1 = new javax.swing.JPanel();
        SWKlienciLista = new javax.swing.JComboBox<>();
        SWAutaKlientaLista = new javax.swing.JComboBox<>();
        jScrollPane3 = new javax.swing.JScrollPane();
        SWOpis = new javax.swing.JTextArea();
        SWRejestr = new javax.swing.JTextField();
        SWRokProd = new javax.swing.JTextField();
        jButton1 = new javax.swing.JButton();
        jButton2 = new javax.swing.JButton();
        SWTel1 = new javax.swing.JTextField();
        SWTel2 = new javax.swing.JTextField();
        SWTel3 = new javax.swing.JTextField();
        jLabel1 = new javax.swing.JLabel();
        jLabel2 = new javax.swing.JLabel();
        jLabel3 = new javax.swing.JLabel();
        jLabel4 = new javax.swing.JLabel();
        jLabel5 = new javax.swing.JLabel();
        jLabel6 = new javax.swing.JLabel();
        jLabel7 = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.DISPOSE_ON_CLOSE);

        SWKlienciLista.addItemListener(new java.awt.event.ItemListener() {
            public void itemStateChanged(java.awt.event.ItemEvent evt) {
                SWKlienciListaItemStateChanged(evt);
            }
        });

        SWAutaKlientaLista.addItemListener(new java.awt.event.ItemListener() {
            public void itemStateChanged(java.awt.event.ItemEvent evt) {
                SWAutaKlientaListaItemStateChanged(evt);
            }
        });

        SWOpis.setColumns(20);
        SWOpis.setRows(5);
        jScrollPane3.setViewportView(SWOpis);

        SWRejestr.setEditable(false);
        SWRejestr.setEnabled(false);
        SWRejestr.setFocusable(false);

        SWRokProd.setEditable(false);
        SWRokProd.setEnabled(false);
        SWRokProd.setFocusable(false);

        jButton1.setText("Zapisz");
        jButton1.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseReleased(java.awt.event.MouseEvent evt) {
                jButton1MouseReleased(evt);
            }
        });

        jButton2.setText("Anuluj");
        jButton2.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseReleased(java.awt.event.MouseEvent evt) {
                jButton2MouseReleased(evt);
            }
        });

        SWTel1.setEditable(false);
        SWTel1.setEnabled(false);
        SWTel1.setFocusable(false);

        SWTel2.setEditable(false);
        SWTel2.setEnabled(false);
        SWTel2.setFocusable(false);

        SWTel3.setEditable(false);
        SWTel3.setEnabled(false);
        SWTel3.setFocusable(false);

        jLabel1.setText("Klient");

        jLabel2.setText("Auto");

        jLabel3.setText("Nr. Rejestracyjny");

        jLabel4.setText("Rok Produkcji");

        jLabel5.setText("Tel.");

        jLabel6.setText("-");

        jLabel7.setText("-");

        javax.swing.GroupLayout jPanel1Layout = new javax.swing.GroupLayout(jPanel1);
        jPanel1.setLayout(jPanel1Layout);
        jPanel1Layout.setHorizontalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jScrollPane3, javax.swing.GroupLayout.Alignment.TRAILING)
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel1Layout.createSequentialGroup()
                        .addComponent(jButton2)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addComponent(jButton1))
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                                .addComponent(SWAutaKlientaLista, 0, 168, Short.MAX_VALUE)
                                .addComponent(SWKlienciLista, 0, 168, Short.MAX_VALUE))
                            .addComponent(jLabel2))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel1Layout.createSequentialGroup()
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                .addComponent(jLabel5)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(SWTel1, javax.swing.GroupLayout.PREFERRED_SIZE, 33, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(jLabel7)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(SWTel2, javax.swing.GroupLayout.PREFERRED_SIZE, 33, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(jLabel6)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(SWTel3, javax.swing.GroupLayout.PREFERRED_SIZE, 33, javax.swing.GroupLayout.PREFERRED_SIZE))
                            .addGroup(jPanel1Layout.createSequentialGroup()
                                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addComponent(SWRejestr, javax.swing.GroupLayout.PREFERRED_SIZE, 100, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addComponent(jLabel3))
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addComponent(SWRokProd)
                                    .addGroup(jPanel1Layout.createSequentialGroup()
                                        .addComponent(jLabel4)
                                        .addGap(0, 36, Short.MAX_VALUE))))))
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addComponent(jLabel1)
                        .addGap(0, 0, Short.MAX_VALUE)))
                .addContainerGap())
        );
        jPanel1Layout.setVerticalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jLabel1)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(SWKlienciLista, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel5)
                    .addComponent(SWTel1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel7)
                    .addComponent(SWTel2, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel6)
                    .addComponent(SWTel3, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel2)
                    .addComponent(jLabel3)
                    .addComponent(jLabel4))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(SWAutaKlientaLista, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(SWRejestr, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(SWRokProd, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(jScrollPane3, javax.swing.GroupLayout.DEFAULT_SIZE, 125, Short.MAX_VALUE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jButton1)
                    .addComponent(jButton2))
                .addGap(9, 9, 9))
        );

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void SWKlienciListaItemStateChanged(java.awt.event.ItemEvent evt) {//GEN-FIRST:event_SWKlienciListaItemStateChanged
        int i = SWKlienciLista.getSelectedIndex();
        if(i >= 0)
            selKlient = klienci[i];
        else
            selKlient = null;
        resetText1();
    }//GEN-LAST:event_SWKlienciListaItemStateChanged

    private void SWAutaKlientaListaItemStateChanged(java.awt.event.ItemEvent evt) {//GEN-FIRST:event_SWAutaKlientaListaItemStateChanged
        int i = SWAutaKlientaLista.getSelectedIndex();
        if(i >= 0)
            selAuto = auta[SWAutaKlientaLista.getSelectedIndex()];
        else
            selAuto = null;
        resetText2();
    }//GEN-LAST:event_SWAutaKlientaListaItemStateChanged

    private void jButton1MouseReleased(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_jButton1MouseReleased
        if(selKlient != null && selAuto != null)
        {
            try {
                    DataControl.NoweZgloszenie(selKlient.getId(),selAuto.getId(),SWOpis.getText());
            } catch (SQLException ex) {
                Logger.getLogger(Panel_NoweZgloszenie.class.getName()).log(Level.SEVERE, null, ex);
            }
            reset();
            x.reset();
            setVisible(false);
        }
    }//GEN-LAST:event_jButton1MouseReleased

    private void jButton2MouseReleased(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_jButton2MouseReleased
        reset();
        setVisible(false);
    }//GEN-LAST:event_jButton2MouseReleased

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JComboBox<String> SWAutaKlientaLista;
    private javax.swing.JComboBox<String> SWKlienciLista;
    private javax.swing.JTextArea SWOpis;
    private javax.swing.JTextField SWRejestr;
    private javax.swing.JTextField SWRokProd;
    private javax.swing.JTextField SWTel1;
    private javax.swing.JTextField SWTel2;
    private javax.swing.JTextField SWTel3;
    private javax.swing.JButton jButton1;
    private javax.swing.JButton jButton2;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JLabel jLabel6;
    private javax.swing.JLabel jLabel7;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JScrollPane jScrollPane3;
    // End of variables declaration//GEN-END:variables
}
