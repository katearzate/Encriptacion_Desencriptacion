package linuxcommands;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.nio.file.Files;
import java.nio.file.attribute.PosixFilePermission;
import java.util.HashSet;
import java.util.Set;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author katearzate
 */
public class window extends javax.swing.JFrame {

    
    public window() {
        initComponents();
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        btnEnterCommand = new javax.swing.JButton();
        listResult = new java.awt.List();
        jButton1 = new javax.swing.JButton();
        jButton2 = new javax.swing.JButton();
        jTextField1 = new javax.swing.JTextField();
        commandText = new javax.swing.JTextField();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        btnEnterCommand.setText("Enter");
        btnEnterCommand.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnEnterCommandActionPerformed(evt);
            }
        });

        jButton1.setText("Add user");

        jButton2.setText("Delete user");

        jTextField1.setText("Enter username...");

        commandText.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                commandTextActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jTextField1)
                    .addComponent(listResult, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                        .addComponent(jButton1, javax.swing.GroupLayout.PREFERRED_SIZE, 200, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(18, 18, 18)
                        .addComponent(jButton2, javax.swing.GroupLayout.DEFAULT_SIZE, 202, Short.MAX_VALUE))
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                        .addComponent(commandText)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addComponent(btnEnterCommand, javax.swing.GroupLayout.PREFERRED_SIZE, 81, javax.swing.GroupLayout.PREFERRED_SIZE)))
                .addContainerGap())
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(btnEnterCommand, javax.swing.GroupLayout.DEFAULT_SIZE, 26, Short.MAX_VALUE)
                    .addComponent(commandText))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(listResult, javax.swing.GroupLayout.PREFERRED_SIZE, 144, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 40, Short.MAX_VALUE)
                .addComponent(jTextField1, javax.swing.GroupLayout.PREFERRED_SIZE, 27, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jButton1)
                    .addComponent(jButton2))
                .addContainerGap())
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void btnEnterCommandActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnEnterCommandActionPerformed
        String[] datos = commandText.getText().split(" ");
        
        //TODO: validacion de que no son más de 3 espacios
        
        switch(datos[0]){
            //************************* CP COMMAND ******************************
            case "cp": 
                listResult.clear();
                String source = datos[1];
                String[] parts = source.split("/");
        
                int c=-1;
                for(String i: parts){
                    c++;
                }
                String destination = datos[2]+parts[c]+"-copy";
                
                File org = new File(source);
                File des = new File(destination);
                
                try{
                    InputStream in = new FileInputStream(org);
                    OutputStream out = new FileOutputStream(des);

                    byte[] buf = new byte[1024];
                    int len;

                    while ((len = in.read(buf)) > 0) {
                        out.write(buf, 0, len);
                    }
                    in.close();
                    out.close();
                    
                    listResult.add("Archivo copiado!");
                }catch(Exception e){
                    System.out.println("error copiando!");
                }
                break;
            //*******************************************************************
            
                
            //************************* LS COMMAND ******************************    
            case "ls": 
                listResult.clear();
                
                File direct = new File(datos[1]); //directorio a listar                                             
                String[] list = direct.list();
                if(list == null){
                    listResult.add("Directorio vacío");
                }else{
                    for (int i = 0; i < list.length; i++) {
                        listResult.add(list[i]);
                    }
                }
                break;    
            //*******************************************************************
                
                
            case "chown":
                //nomUsuario directorio
                break;
                
                
            //************************ CHMOD COMMAND ****************************
            case "chmod":
                listResult.clear();
                
                File filePer = new File(datos[2]);
                Set<PosixFilePermission> perms = new HashSet<>();
                for (int i = 0; i < 3; i++) {
                    switch(datos[1].charAt(i)){
                        case '-':
                            System.out.println("-");
                            break;
                        case '1':
                            switch(i){
                                case 0: 
                                    perms.add(PosixFilePermission.OWNER_EXECUTE);
                                    break;
                                case 1:
                                    perms.add(PosixFilePermission.GROUP_EXECUTE);
                                    break;
                                case 2:
                                    perms.add(PosixFilePermission.OTHERS_EXECUTE);
                                    break;
                            }
                            break;
                        case '2':
                            switch(i){
                                case 0: 
                                    perms.add(PosixFilePermission.OWNER_WRITE);
                                    break;
                                case 1:
                                    perms.add(PosixFilePermission.GROUP_WRITE);
                                    break;
                                case 2:
                                    perms.add(PosixFilePermission.OTHERS_WRITE);
                                    break;
                            }
                            break;
                        case '3':
                            switch(i){
                                case 0: 
                                    perms.add(PosixFilePermission.OWNER_EXECUTE);
                                    perms.add(PosixFilePermission.OWNER_WRITE);
                                    break;
                                case 1:
                                    perms.add(PosixFilePermission.GROUP_EXECUTE);
                                    perms.add(PosixFilePermission.GROUP_WRITE);
                                    break;
                                case 2:
                                    perms.add(PosixFilePermission.OTHERS_EXECUTE);
                                    perms.add(PosixFilePermission.OTHERS_WRITE);
                                    break;
                            }
                            break;
                        case '4':
                            switch(i){
                                case 0: 
                                    perms.add(PosixFilePermission.OWNER_READ);
                                    break;
                                case 1:
                                    perms.add(PosixFilePermission.GROUP_READ);
                                    break;
                                case 2:
                                    perms.add(PosixFilePermission.OTHERS_READ);
                                    break;
                            }
                            break;
                        case '5':
                            switch(i){
                                case 0: 
                                    perms.add(PosixFilePermission.OWNER_READ);
                                    perms.add(PosixFilePermission.OWNER_EXECUTE);
                                    break;
                                case 1:
                                    perms.add(PosixFilePermission.GROUP_READ);
                                    perms.add(PosixFilePermission.GROUP_EXECUTE);
                                    break;
                                case 2:
                                    perms.add(PosixFilePermission.OTHERS_READ);
                                    perms.add(PosixFilePermission.OTHERS_EXECUTE);
                                    break;
                            }
                            break;
                        case '6':
                            switch(i){
                                case 0: 
                                    perms.add(PosixFilePermission.OWNER_READ);
                                    perms.add(PosixFilePermission.OWNER_WRITE);
                                    break;
                                case 1:
                                    perms.add(PosixFilePermission.GROUP_READ);
                                    perms.add(PosixFilePermission.GROUP_WRITE);
                                    break;
                                case 2:
                                    perms.add(PosixFilePermission.OTHERS_READ);
                                    perms.add(PosixFilePermission.OTHERS_WRITE);
                                    break;
                            }
                            break;
                        case '7':
                            switch(i){
                                case 0: 
                                    perms.add(PosixFilePermission.OWNER_READ);
                                    perms.add(PosixFilePermission.OWNER_WRITE);
                                    perms.add(PosixFilePermission.OWNER_EXECUTE);
                                    break;
                                case 1:
                                    perms.add(PosixFilePermission.GROUP_READ);
                                    perms.add(PosixFilePermission.GROUP_WRITE);
                                    perms.add(PosixFilePermission.GROUP_EXECUTE);
                                    break;
                                case 2:
                                    perms.add(PosixFilePermission.OTHERS_READ);
                                    perms.add(PosixFilePermission.OTHERS_WRITE);
                                    perms.add(PosixFilePermission.OTHERS_EXECUTE);
                                    break;
                            }
                            break;
                    }
                }
            
                try {
                    Files.setPosixFilePermissions(filePer.toPath(), perms);
                    listResult.add("Permisos cambiados!");
                    
                } catch (IOException ex) {
                    Logger.getLogger(window.class.getName()).log(Level.SEVERE, null, ex);
                    listResult.add("ERROR");
                }
            //*******************************************************************
                
            default:
                break;
        }
        
    }//GEN-LAST:event_btnEnterCommandActionPerformed

    private void commandTextActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_commandTextActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_commandTextActionPerformed

    
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(window.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(window.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(window.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(window.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new window().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton btnEnterCommand;
    private javax.swing.JTextField commandText;
    private javax.swing.JButton jButton1;
    private javax.swing.JButton jButton2;
    private javax.swing.JTextField jTextField1;
    private java.awt.List listResult;
    // End of variables declaration//GEN-END:variables
}
