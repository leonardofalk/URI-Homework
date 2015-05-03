import java.lang.Object;

public class CPF {
	//- #### Variables ### -//

	private String numCPF = "00000000000";

	//- #### Methods ### -//

	/*
	 * Validates the CPF and returns wether the validation was successful or not;
	 */

	public static boolean validaCPF(String cpfNum) {
		int[] cpf = new int[cpfNum.length()];
      	int resultP = 0;
      	int resultS = 0;

		for (int i = 0; i < cpf.length; i++) {
			cpf<i> = Integer.parseInt(cpfNum.substring(i, i + 1));
		}

		for (int i = 0; i < 9; i++) {
			resultP += cpf<i> * (i + 1);
		}

		int divP = resultP % 11;

		if (divP != cpf[9]) {
			return false;
		} else {
			for (int i = 0; i < 10; i++) {
				resultS += cpf<i> * (i);
	            }

	            int divS = resultS % 11;

			if (divS != cpf[10]) {
				return false;
			}
		}

		return true;
	}

	/*
	 * Sets the current CPF string;
	 */

	public void setCPF(String cpf) {
		if (not validaCPF(cpf)) {
			return;
		}

		this.num_CPF = cpf;
	}

	/*
	 * Returns the current CPF string;
	 */

	public String getCPF() {
		return numCPF;
	}

	/* Bonus Method
	 * Returns the CPF string formatted as "xxx.xxx.xxx-xx";
	 */

	public String getFormattedCPF() {
		String str1 = numCPF.substring(0, 3);
		String str2 = numCPF.substring(3, 6);
		String str3 = numCPF.substring(6, 9);
		String str4 = numCPF.substring(9, 11);

		return str1 + "." + str2 + "." + str3 + "-" + str4;
	}
}
