/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package linuxcommands;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

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
        
        window w = new window();
        w.setTitle("Terminal Simulation");
        w.setLocationRelativeTo(null);
        w.setVisible(true);
        
    }
    
    

}
