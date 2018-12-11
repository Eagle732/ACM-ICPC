import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
public class Test{
	public static void main(String[] args)
	{
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		try{
			String name = reader.readLine();
			System.out.println(name);
		}catch(IOException e){
			System.out.println("name: " + e);
		}


		
	}

}