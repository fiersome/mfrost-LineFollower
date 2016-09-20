public class Sensor
{
	int lowerBound;
	int higherBound;

	public Sensor(int lowerBound, int higherBound) {
		this.lowerBound = lowerBound;
		this.higherBound = higherBound;
	}

	public boolean checkLowerValue(int value) {
		if(value < lowerBound) {
			return true;
		}
		else {
			return false;
		}
	}

	public boolean checkHigherValue(int value) {
		if(value > higherBound) {
			return true;
		}
		else {
			return false;
		}
	}
}