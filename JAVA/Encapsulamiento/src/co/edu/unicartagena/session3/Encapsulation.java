/*
Copyright (c) 2019 - 2024, Juan Carlos Garcia Ojeda, Universidad de Cartagena
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.
   
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

package co.edu.unicartagena.session3;
/*
import co.edu.unicartagena.session3.package1.Class1;
import co.edu.unicartagena.session3.package3.Class2Son;
 */
 
public class Encapsulation {

    int atributo1=100;
    public int atributo2=200;
    public int atributo3=300;
    protected int atributo4=400;
    
    public static void main(String[] args) {
        /*//MISMA CLASE
        App app = new App();
        System.out.println(app.atributo1);
        System.out.println(app.atributo2);
        System.out.println(app.atributo3);
        System.out.println(app.atributo4);
        */     
        
        /*
        Encapsulation enc1 = new Encapsulation();
        System.out.println(enc1.atributo1);
        System.out.println(enc1.atributo2);
        System.out.println(enc1.atributo3);
        System.out.println(enc1.atributo4);
        */
        //MISMO PAQUETE
        /*Clase0 cls0 = new Clase0();
        System.out.println(cls0.atributo1);
        System.out.println(cls0.atributo2);
        System.out.println(cls0.getAtributo3());
        System.out.println(cls0.atributo4);
         */
            
        //UNIVERSO
        /*Clase1 cls1 = new Clase1();
        System.out.println(cls1.atributo1);
        System.out.println(cls1.atributo2);
        System.out.println(cls1.atributo3);
        System.out.println(cls1.atributo4);
        */
              
        //SubClase
        //Class2Son cls2hijo = new Class2Son();
        //System.out.println(cls2hijo.atributo1);
        //System.out.println(cls2hijo.atributo2);
        //System.out.println(cls2hijo.atributo3);
        //System.out.println(cls2hijo.alltributo4);        
    }
    
}
