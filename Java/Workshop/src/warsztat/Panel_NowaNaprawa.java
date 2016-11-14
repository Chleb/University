/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package warsztat;

import java.sql.SQLException;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.DefaultListModel;

/**
 *
 * @author Karol
 */
public class Panel_NowaNaprawa extends javax.swing.JDialog {

    Zgloszenie[] wolne;
    Zgloszenie selZgl;
    Panel_Naprawa x;
    public Panel_NowaNaprawa(java.awt.Frame parent, boolean modal, Panel_Naprawa x) {
        super(parent, modal);
        initComponents();
        this.x = x;
        reset();
    }

    public void reset()
    {
        SWWolne.removeAllItems();
        SWOpis.setText("");
        SWKoszt.setText("");
        try {
            wolne = DataControl.wolneZgl();
            for(int i = 0; i < wolne.length; i++)
            {
                SWWolne.addItem(wolne[i].auto);
            }
            if(wolne.length > 0)
                selZgl = wolne[0];
            else
                selZgl = null;
            resetText();
        } catch (SQLException ex) {
            Logger.getLogger(Panel_NowaNaprawa.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
    public void resetText()
    {
        if(selZgl != null)
            SWOpis.setText(selZgl.opis);
        else
            SWOpis.setText("");
    }
    
    
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jLabel1 = new javax.swing.JLabel();
        SWWolne = new javax.swing.JComboBox<>();
        jLabel2 = new javax.swing.JLabel();
        SWKoszt = new javax.swing.JFormattedTextField();
        jScrollPane1 = new javax.swing.JScrollPane();
        SWOpis = new javax.swing.JTextArea();
        jLabel3 = new javax.swing.JLabel();
        jButton1 = new javax.swing.JButton();
        jButton2 = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.DISPOSE_ON_CLOSE);

        jLabel1.setText("Wolne Zgłoszenia");

        SWWolne.addItemListener(new java.awt.event.ItemListener() {
            public void itemStateChanged(java.awt.event.ItemEvent evt) {
                SWWolneItemStateChanged(evt);
            }
        });

        jLabel2.setText("Wstępny koszt");

        SWKoszt.setFormatterFactory(new javax.swing.text.DefaultFormatterFactory(new javax.swing.text.NumberFormatter(new java.text.DecimalFormat("#0"))));

        SWOpis.setEditable(false);
        SWOpis.setColumns(20);
        SWOpis.setRows(5);
        SWOpis.setFocusable(false);
        jScrollPane1.setViewportView(SWOpis);

        jLabel3.setText("Opis");

        jButton1.setText("Anuluj");
        jButton1.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseReleased(java.awt.event.MouseEvent evt) {
                jButton1MouseReleased(evt);
            }
        });

        jButton2.setText("Podejmij");
        jButton2.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseReleased(java.awt.event.MouseEvent evt) {
                jButton2MouseReleased(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                            .addComponent(jLabel1)
                            .addComponent(SWWolne, 0, 125, Short.MAX_VALUE)
                            .addComponent(jLabel2)
                            .addComponent(SWKoszt))
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(layout.createSequentialGroup()
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(jScrollPane1)
                                .addContainerGap())
                            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 114, Short.MAX_VALUE)
                                .addComponent(jLabel3)
                                .addGap(128, 128, 128))))
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(jButton1)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addComponent(jButton2)
                        .addContainerGap())))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(jLabel3)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 71, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(jLabel1)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(SWWolne, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(jLabel2)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(SWKoszt, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jButton1)
                    .addComponent(jButton2))
                .addContainerGap())
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void SWWolneItemStateChanged(java.awt.event.ItemEvent evt) {//GEN-FIRST:event_SWWolneItemStateChanged
        int i = SWWolne.getSelectedIndex();
        if(i >= 0)
            selZgl = wolne[i];
        else
            selZgl = null;
        resetText();
    }//GEN-LAST:event_SWWolneItemStateChanged

    private void jButton1MouseReleased(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_jButton1MouseReleased
        reset();
        setVisible(false);
    }//GEN-LAST:event_jButton1MouseReleased

    private void jButton2MouseReleased(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_jButton2MouseReleased
        if(selZgl != null)
            try {
                DataControl.NowaNaprawa(Integer.parseInt(SWKoszt.getText()), selZgl.id);
        } catch (SQLException ex) {
            Logger.getLogger(Panel_NowaNaprawa.class.getName()).log(Level.SEVERE, null, ex);
        }
        reset();
        x.reset();
        setVisible(false);
    }//GEN-LAST:event_jButton2MouseReleased


    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JFormattedTextField SWKoszt;
    private javax.swing.JTextArea SWOpis;
    private javax.swing.JComboBox<String> SWWolne;
    private javax.swing.JButton jButton1;
    private javax.swing.JButton jButton2;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JScrollPane jScrollPane1;
    // End of variables declaration//GEN-END:variables
}
