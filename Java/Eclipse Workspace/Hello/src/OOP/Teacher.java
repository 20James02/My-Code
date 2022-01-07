package OOP;

import java.util.Calendar;

public class Teacher extends Student{
	public String name;
	public String code;
	public int birthday;
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public String getCode() {
		return code;
	}
	public void setCode(String code) {
		this.code = code;
	}
	public int getBirthday() {
		return birthday;
	}
	public void setBirthday(int birthday) {
		this.birthday = birthday;
	}
	public int getAge() {
		int age = 0;
		//Lay gia tri nam hien tai bang Calendar
		Calendar now = Calendar.getInstance();
		age = now.get(Calendar.YEAR) - this.getBirthday();
		return age;
	}
	public void showInfo() {
		//Ghi de bang super
		super.showInfo();
	}
}
