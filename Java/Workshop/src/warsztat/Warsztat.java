package warsztat;

public class Warsztat {

    public static void main(String args[]) {
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(AdminFrame.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(AdminFrame.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(AdminFrame.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(AdminFrame.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        
      Logowanie dialog = new Logowanie(new javax.swing.JFrame(), true);
      dialog.setVisible(true);}
    
    
    public static void startAdmin()
    {
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new AdminFrame().setVisible(true);
            }
        });
    }
    public static void startMechanik(){
            java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new FrameMechanik().setVisible(true);
            }
        });
    }
    
    public static void startSekretarz(){
            java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new FrameSekretarz().setVisible(true);
            }
        });
    }
}
