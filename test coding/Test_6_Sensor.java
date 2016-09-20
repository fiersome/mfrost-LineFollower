import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Test_6_Sensor 
{
	public static void main(String[] args) 
	{
		try {
			BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
			String input = reader.readLine();
			Sensor_6 robot = new Sensor_6();


			/** mengolah inputan standar **/
			while(input != null) {
				String[] input2 = input.split(" ");
				int[] hasil = {0,0,0,0,0,0};
				for(int i = 0; i < hasil.length; i++) {
					hasil[i] = Integer.parseInt(input2[i]);
				}

				int hasil2 = robot.checkInput(hasil);

				robot.followLine(hasil2);



				input = reader.readLine();
			}
			
		}
		catch (IOException e) {
				
		}

	}
}