import Matematica.*;
import org.omg.CosNaming.*; 
import org.omg.CORBA.*;
import org.omg.PortableServer.*; 

public class Cliente{

  public static void main(String args[]){
  try {
 
 	ORB orb = ORB.init(args,null);
	org.omg.CORBA.Object obj = orb.resolve_initial_references("NameService");

 	NamingContext naming = NamingContextHelper.narrow(obj);
	
	NameComponent[] name = {new NameComponent("Calculadora","Exemplo")};

	org.omg.CORBA.Object objRef =  naming.resolve(name);

	Calculadora calc = CalculadoraHelper.narrow(objRef);		

	 try{

	  System.out.println("5+3="+ calc.soma(5,3));
	  System.out.println("5/0="+ calc.divisao(5,0));

	 }catch (DivisaoPorZero ex){
  	    System.out.println("Divisao Por Zero");
	    System.out.println("A Diviao foi "+ex.arg1 +"/ "+ex.arg2); }

    }catch (Exception e) {
  	System.out.println("Outro Erro : " + e) ;
	  e.printStackTrace(System.out); }
   }
}
