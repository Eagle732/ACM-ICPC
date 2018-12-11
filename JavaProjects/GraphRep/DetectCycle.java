import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

class Graph
{
	private final int v;
	private final List<List<Integer>> adj;

	public Graph(int V)
	{
		this.V = V;
		adj = new ArrayList<>(V);
		for(int i=0;i<V;i++)
		{
			adj.add(new LinkedList<>());
		}
	}

	





}