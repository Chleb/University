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
public class Panel_DodajCzesc extends javax.swing.JDialog {

    Czesc_zamienna[] czesci;
    Czesc_zamienna selCzesc;
    Panel_Naprawa x;
    
    public Panel_DodajCzesc(java.awt.Frame parent, boolean modal, Panel_Naprawa x) {
        super(parent, modal);
        initComponents();
        this.x = x;
    }

    public void reset()
    {
        try {
            selCzesc = null;
            SWCzesci.removeAllItems();
            SWIlosc.setValue(0);
            czesci = DataControl.WszCzesci();
            for(int i = 0; i < czesci.length; i++)
            {
                SWCzesci.addItem(czesci[i].model + " " + czesci[i].nazwa + ": " + czesci[i].ilosc);
            }
            if(czesci.length > 0)
            {
                selCzesc = czesci[0];
                SWIlosc.setModel(new javax.swing.SpinnerNumberModel(0, 0, selCzesc.ilosc, 1));
            }
            else
                SWIlosc.setModel(new javax.swing.SpinnerNumberModel(0, 0, selCzesc.ilosc, 1));
        } catch (SQLException ex) {
            Logger.getLogger(Panel_DodajCzesc.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        SWCzesci = new javax.swing.JComboBox<>();
        SWIlosc = new javax.swing.JSpinner();
        jButton1 = new javax.swing.JButton();
        jButton2 = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.DISPOSE_ON_CLOSE);

        SWCzesci.setModel(new javax.swing.DefaultComboBoxModel<>(new String[] { "Item 1", "Item 2", "Item 3", "Item 4" }));
        SWCzesci.addItemListener(new java.awt.event.ItemListener() {
            public void itemStateChanged(java.awt.event.ItemEvent evt) {
                SWCzesciItemStateChanged(evt);
            }
        });

        SWIlosc.setModel(new javax.swing.SpinnerNumberModel(0, 0, 0, 1));

        jButton1.setText("Anuluj");
        jButton1.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseReleased(java.awt.event.MouseEvent evt) {
                jButton1MouseReleased(evt);
            }
        });

        jButton2.setText("Dodaj");
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
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(SWCzesci, javax.swing.GroupLayout.PREFERRED_SIZE, 217, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                        .addComponent(SWIlosc)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(jButton1)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(jButton2)))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(SWCzesci, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(SWIlosc, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jButton2)
                    .addComponent(jButton1))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void jButton2MouseReleased(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_jButton2MouseReleased
        if(selCzesc != null)
        {
            try {
                DataControl.DodajCzesc(selCzesc.id,x.selNap.id,(int)SWIlosc.getValue());
            } catch (SQLException ex) {
                Logger.getLogger(Panel_DodajCzesc.class.getName()).log(Level.SEVERE, null, ex);
            }
            reset();
            x.resetText();
            setVisible(false);
        }
    }//GEN-LAST:event_jButton2MouseReleased

    private void jButton1MouseReleased(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_jButton1MouseReleased
        reset();
        setVisible(false);
    }//GEN-LAST:event_jButton1MouseReleased

    private void SWCzesciItemStateChanged(java.awt.event.ItemEvent evt) {//GEN-FIRST:event_SWCzesciItemStateChanged
        int n = SWCzesci.getSelectedIndex();
        if(n >= 0)
        {
            selCzesc = czesci[n];
            SWIlosc.setModel(new javax.swing.SpinnerNumberModel(0, 0, selCzesc.ilosc, 1));
        }
        else
            reset();
    }//GEN-LAST:event_SWCzesciItemStateChanged


    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JComboBox<String> SWCzesci;
    private javax.swing.JSpinner SWIlosc;
    private javax.swing.JButton jButton1;
    private javax.swing.JButton jButton2;
    // End of variables declaration//GEN-END:variables
}
