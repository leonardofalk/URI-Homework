/* Not finished */

public class Date {
	/* Constants */
	public final int MONTH_JANUARY	 = 01;
	public final int MONTH_FEBRUARY  = 02;
	public final int MONTH_MARCH     = 03;
	public final int MONTH_APRIL     = 04;
	public final int MONTH_MAY       = 05;
	public final int MONTH_JUNE      = 06;
	public final int MONTH_JULY      = 07;
	public final int MONTH_AUGUST    = 08;
	public final int MONTH_SEPTEMBER = 09;
	public final int MONTH_OCTOBER   = 10;
	public final int MONTH_NOVEMBER  = 11;
	public final int MONTH_DECEMBER  = 12;
	
	/* Private Vars */
	private int day   = 0001;
	private int month = 0001;
	private int year  = 0001;
	
	private int monthsTotalDays = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	private String monthsNames = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	
	/* Public Methods, Functions, Getters and Setters */
	public static void Date();
	
	public static void Date(int d, int m, int y) {
		day = d;
		month = m;
		year = y;
		
		if !(validateDate()) {
			day   = 0001;
			month = 0001;
			year  = 0001;
		}
	}

	public void setDay(int day) {
		this.day = day;
	}

	public void setMonth(int month) {
		this.month = month;
	}
	
	public void setYear(int year) {
		this.year = year;
	}
		
	public int getDay() {
		return this.day;
	}
		
	public int getMonth() {
		return this.month;
	}
		
	public int getYear() {
		return this.Year;
	}
		
	public boolean isLeapYear() {
		return this.year % 4 == 0 && (this.year % 100 != 0 || this.year % 400 == 0);
	}
		
	public static boolean validateDate()
		return (month <= 12 && month >= 1 && 
		       (day >= 1 && (day <= monthsTotalDays[month - 1] or (isLeapYear() && month == 2 && day <= 29))) && 
		       (year > 0);
	}
		
	public String getMonthName() {
		return monthsNames[month - 1];
	}
		
	public String getDateFormatted() {
		String dd, mm, yy;
			
		if (day < 10) {
			dd = "0" + day;
		} else {
			dd = "" + day;
		}
		
		if (month < 10) {
			mm = "0" + month;
		} else {
			mm = "" + month;
		}
			
		return dd + "/" + mm + "/" + year;
	}
		
	public String getDateFormattedExtense() {
		return day + " de " + getMonthName() + " de " + year;
	}
}
