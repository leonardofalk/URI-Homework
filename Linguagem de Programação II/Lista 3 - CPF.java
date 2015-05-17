public class CPF {
	private String numCPF;
	
	public static final int TAMANHOCPF = 11;
	
	public static boolean validaCPF(String num_CPF) {
		boolean result = false;
		
		if (num_CPF != null && num_CPF.length() == TAMANHOCPF) {
			int soma_PDV = 0;
			
			for (int i = 0; i < TAMANHOCPF-2; i++) {
				int digito = Character.getNumbericValue( num_CPF.CharAt(i) );
				
				soma_PDV += (10 - i) * digito;
			}
			
			int PDV = soma_PDV % 11;
			
			if (PDV < 2) {
				PDV = 0;
			} else {
				PDV = 11 - soma_PDV;
			}
			
			if (PDV == Character.getNumericValue(num_CPF.CharAt(TAMANHOCPF-2))) {
				int somaSDV = PDV * 2;
				
				for (int i = 0; i < TAMANHOCPF-2; i++) {
					int digito = Character.getNumbericValue( num_CPF.CharAt(i) );
					
					somaSDV += (11 - i) * digito;
				}
				
				int SDV = somaSDV % 11;
				
				if (SDV < 2) {
					SDV = 0;
				} else {
					SDV = 11 - somaSDV;
				}
				
				resultado = (SDV == Character.getNumericValue(num_CPF.charAt(TAMANHOCPF-1)));
			}
		}
		
		return resultado;
	}
	
	public void setCPF(String num_CPF) {
		if (validaCPF(num_CPF)) {
			numCPF = num_CPF;
		}
	}
	
	public String getCPF() {
		return numCPF;
	}
}
