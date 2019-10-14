import Matematica.*;

public class CalculadoraImpl extends CalculadoraPOA{
	public float soma(float arg1, float arg2){
	  	System.out.println("Soma = "+arg1+" + "+arg2);
		return arg1 + arg2;
	}
	public float divisao(float arg1, float arg2) throws DivisaoPorZero{
  		  System.out.println("Divisao="+arg1+"/"+arg2);
		  if (arg2 == 0)  throw new DivisaoPorZero(arg1,arg2);
  	          return arg1 / arg2;   
        }
}
