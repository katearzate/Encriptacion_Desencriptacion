/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package linuxcommands;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.attribute.PosixFilePermission;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

/**
 *
 * @author katearzate
 */
public class LinuxCommands {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws FileNotFoundException, IOException {
        Scanner read = new Scanner(System.in);
        /*
        String command = "7-- /home/katearzate/Desktop/ej";
        
        String[] datos = command.split(" ");
        File file = new File(datos[1]);
        
        Set<PosixFilePermission> perms = new HashSet<>();
        
        for (int i = 0; i < 3; i++) {
            switch(datos[0].charAt(i)){
                case '-':
                    System.out.println("ningun permiso");
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
        Files.setPosixFilePermissions(file.toPath(), perms);
        */
        
        window w = new window();
        w.setTitle("Terminal Simulation");
        w.setLocationRelativeTo(null);
        w.setVisible(true);
        
    }
}
