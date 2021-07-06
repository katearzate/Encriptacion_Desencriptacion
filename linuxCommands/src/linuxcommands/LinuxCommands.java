/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package linuxcommands;

import java.io.File;
import java.util.Scanner;

/**
 *
 * @author katearzate
 */
public class LinuxCommands {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        /*Scanner read = new Scanner(System.in);
        
        String command, directory = "";
        
        command = read.nextLine(); //command entered
        
        String[] datos = command.split(" ");

        switch(datos[0]){
            case "cp": 
                System.out.println("solo 1 comando");
                break;
            case "ls": 
                for(String i: datos){
                    directory = i;
                }
                break;
            default:
                System.out.println("Comando incorrecto");
                break;
        }
        
        
        File directorio = new File(directory); //directorio a listar                                             
        String[] lista = directorio.list();
        if(lista == null){
            System.out.println("\n* * directorio incorrecto * *");
        }else{
            for (int i = 0; i < lista.length; i++) {
                System.out.println(lista[i]);
            }
        }
        */
        
        
        window w = new window();
        w.setTitle("Terminal Simulation");
        w.setLocationRelativeTo(null);
        w.setVisible(true);
        
    }
    
}
