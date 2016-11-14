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
public class AdminFrame extends javax.swing.JFrame {

    /**
     * Creates new form AdminFrame
     */
    public AdminFrame() {
        initComponents();
    }
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jTabbedPane1 = new javax.swing.JTabbedPane();
        panel_Naprawa1 = new warsztat.Panel_Naprawa();
        panel_Zgloszenia1 = new warsztat.Panel_Zgloszenia();
        panel_Klienci1 = new warsztat.Panel_Klienci();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        jTabbedPane1.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseReleased(java.awt.event.MouseEvent evt) {
                jTabbedPane1MouseReleased(evt);
            }
        });
        jTabbedPane1.addTab("Naprawa", panel_Naprawa1);
        jTabbedPane1.addTab("Zgłoszenia", panel_Zgloszenia1);
        jTabbedPane1.addTab("Klienci", panel_Klienci1);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jTabbedPane1, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.DEFAULT_SIZE, 525, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jTabbedPane1, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.PREFERRED_SIZE, 333, Short.MAX_VALUE)
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void jTabbedPane1MouseReleased(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_jTabbedPane1MouseReleased
        panel_Naprawa1.reset();
        panel_Klienci1.reset();
        panel_Zgloszenia1.reset();
    }//GEN-LAST:event_jTabbedPane1MouseReleased


    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JTabbedPane jTabbedPane1;
    private warsztat.Panel_Klienci panel_Klienci1;
    private warsztat.Panel_Naprawa panel_Naprawa1;
    private warsztat.Panel_Zgloszenia panel_Zgloszenia1;
    // End of variables declaration//GEN-END:variables
}
