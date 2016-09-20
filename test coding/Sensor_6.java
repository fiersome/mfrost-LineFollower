public class Sensor_6
{
	Sensor sensor1;
	Sensor sensor2;
	Sensor sensor3;
	Sensor sensor4;
	Sensor sensor5;
	Sensor sensor6;

	public Sensor_6 () {
		sensor1 = new Sensor(25, 80);
		sensor2 = new Sensor(25, 100);
		sensor3 = new Sensor(15, 85);
		sensor4 = new Sensor(50, 170);
		sensor5 = new Sensor(60, 170);
		sensor6 = new Sensor(65, 210);
	}

	public int checkInput(int[] input) {
		int masukkan = 0b000000;
		if(!sensor6.checkLowerValue(input[5])) {
			masukkan += 0b000001;
		}

		if(!sensor5.checkLowerValue(input[4])) {
			masukkan += 0b000010;
		}

		if(!sensor4.checkLowerValue(input[3])) {
			masukkan += 0b000100;
		}

		if(!sensor3.checkLowerValue(input[2])) {
			masukkan += 0b001000;
		}

		if(!sensor2.checkLowerValue(input[1])) {
			masukkan += 0b010000;
		}

		if(!sensor1.checkLowerValue(input[0])) {
			masukkan += 0b100000;
		}
		return masukkan;
	}

	public void followLine(int input) {
		if(input == 0b110011 || input == 0b000000 || input == 0b100001 || input == 0b000001 || input == 0b100000) {
			System.out.println("maju");
		}
		else if (input == 0b110111 || input == 0b101111 || input == 0b100111) {
			System.out.println("belok kiri");
		}

		else if(input == 0b011111 || input == 0b001111 || input == 0b000111) {
			System.out.println("belok kiri 90 derajat");
		}

		else if(input == 0b111011 || input ==  0b111101 || input == 0b111001) {
			System.out.println("belok kanan");
		}

		else if(input == 0b111110 || input == 0b111100 || input == 0b111000) {
			System.out.println("belok kanan 90 derajat");
		}
		else if(input == 0b111111) {
			System.out.println("berhenti");
		}
	}
}