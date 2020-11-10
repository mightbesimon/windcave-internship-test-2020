/**
 *	Programming Test (2020) - Windcave
 *	QUESTION ONE - Polygons
 *	@author Simon Shan | qsha020@aucklanduni.ac.nz
 */


/**
 * Template for *regular* polygons (same length for all sides).
 */
abstract class Polygon {

	protected int    _numSides;
	protected double _lenSides;

	public abstract double area();

	/** String representation of this shape. */
	public String toString() {
		return String.format("[%-8s] %d sides, length = %.2f, area = %.2f",
					getClass().getName(), _numSides, _lenSides, area());
	}

	/** Getter for _numSides. */
	public int numSides() {
		return _numSides;
	}
}

/**
 * Implementation of regular pentagons.
 */
class Pentagon extends Polygon {

	/** Construct default Pentagon. */
	public Pentagon() {
		this(1.0);	// default length = 1.0
	}

	/** Construct Pentagon with custom length.
	 * @param length of sides. */
	public Pentagon(double length) {
		_numSides = 5;
		_lenSides = length;
	}

	/** Calculate the area. */
	public double area() {
		return 1.720477401 * _lenSides * _lenSides;
	}
}

/**
 * Implementation of squares.
 */
class Square extends Polygon {

	/** Construct default Square. */
	public Square() {
		this(1.0);	// default length = 1.0
	}

	/** Construct Square with custom length.
	 * @param length of sides. */
	public Square(double length) {
		_numSides = 4;
		_lenSides = length;
	}

	/** Calculate the area. */
	public double area() {
		return _lenSides * _lenSides;
	}
}

/**
 * Implementation of equilateral triangles.
 */
class Triangle extends Polygon {

	/** Construct default Triangle.
	 */
	public Triangle() {
		this(1.0);	// default length = 1.0
	}

	/** Construct Triangle with custom length.
	 * @param length of sides. */
	public Triangle(double length) {
		_numSides = 3;
		_lenSides = length;
	}

	/** Calculate the area. */
	public double area() {
		return 0.4330127019 * _lenSides * _lenSides;
	}
}

////////////////////////////////////////////////////////////////
////                    MAIN STARTS HERE                    ////
////////////////////////////////////////////////////////////////
public class Question1 {

	public static void main(String[] args) {
		System.out.println(" polygon |  sides  |    length    |    area");
		System.out.printf("%s\n%s\n%s\n",
			new Pentagon(),
			new   Square(),
			new Triangle()
		);
	}
}
