//Not finished
//ta INCOMPLETO, se puderem contribuir fiquem avontade


public class CPF {
	
	private String numCPF;


		String bloco1 = numCPF.substring(0,3);
		String bloco2 = numCPF.substring(3,6);
		String bloco3 = numCPF.substring(6,9);
		String bloco4 = numCPF.substring(9,11);




	public static boolean validaCPF(num_CPF String) {

		public int soma = 0;
		public int resultado;
		public int pdv;
		public int sdv;

		//encontrar o primeiro digito PDV
		String num;
		for (int i=10; i>=2; i--){
      num = numCPF.substring(10-i, 11-i);
      int nucp = Integer.parseInt(num);
      soma += nucp * i);
		}

		resultado = soma % 11;



		if (resultado == 1 || resultado == 0){
			pdv = 0;
		} else {
			pdv = (resultado - 11);
		}

		//encontrar o segundo digio SDV
		soma = 0;
		String num;
		for (int i=11; i<=3; i--) {
			num = numCPF.substring(11-i, 12-i);
			int nucp = Integer.parseInt(num);
			soma += nucp * i;
		}

		soma += pdv * 2;

		resultado = soma % 11;

		if (resultado == 1 || resultado == 0 ){
			sdv = 0;
		} else {
			sdv = resultado - 11;
		}

		cpf = bloco1+"."+bloco2+"."+bloco3+"-"bloco4;
		System.out.prinln(cpf)




	}





	public String getCPF() {
		return numCPF;
	}

	public boolean setCPF(num_CPF String) {
		this.num_CPF = num_CPF;
	}

}
