import Matematica.*;
import org.omg.CosNaming.*; 
import org.omg.CORBA.*;
import org.omg.PortableServer.*;

public class Servidor{

 public static void main(String args[]){
 try{
	ORB orb = ORB.init(args,null); 	

		
	org.omg.CORBA.Object objPoa = orb.resolve_initial_references("RootPOA");
	
	POA rootPOA = POAHelper.narrow(objPoa);		


	org.omg.CORBA.Object obj = orb.resolve_initial_references("NameService");

	NamingContext naming = NamingContextHelper.narrow(obj);

	CalculadoraImpl calc = new CalculadoraImpl();

	org.omg.CORBA.Object   objRef =	 rootPOA.servant_to_reference(calc);


	NameComponent[] name = {new NameComponent("Calculadora","Exemplo")};

	naming.rebind(name,objRef);

	rootPOA.the_POAManager().activate();

	System.out.println("Servidor Pronto ...");

	orb.run();

   }catch (Exception ex){
		System.out.println("Erro");
		ex.printStackTrace();}
  }
}
