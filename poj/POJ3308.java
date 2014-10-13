import java.util.*;

class FlowNetwork {

  private static class FlowEdge {
    private final int v, w;
    private final double capacity;
    private double flow;
    public FlowEdge(int v, int w, double capacity) {
      this.v = v;
      this.w = w;
      this.capacity = capacity;
      this.flow = 0;
    }
    public int from() { return v; }
    public int to() { return w; }
    public int other(int vertex) {
      if(vertex==v)
        return w;
      if(vertex==w)
        return v;
      throw new IllegalArgumentException();
    }
    public double capacity() { return capacity; }
    public double flow() { return flow; }
    public double residualCapacityTo(int vertex) {
      if (vertex==v)
        return flow;
      if (vertex==w)
        return capacity-flow;
      throw new IllegalArgumentException();
    }
    public void addResidualFlowTo(int vertex, double delta) {
      if(vertex==v)
        flow -= delta;
      else if(vertex==w)
        flow += delta;
      else
        throw new IllegalArgumentException();
    }
    public String toString() { return v+"->"+w+" "+flow+"/"+capacity; }
  }

  private final int V, s, t;
  private int E = 0;
  private final LinkedList<FlowEdge>[] adj;
  private Double maxFlow = null;

  @SuppressWarnings({"unchecked", "rawtypes"})
    public FlowNetwork(int V, int s, int t) {
      this.V = V;
      this.s = s;
      this.t = t;
      adj = new LinkedList[V];
      for(int i = 0; i<V; i++)
        adj[i] = new LinkedList<FlowEdge>();
    }

  public FlowNetwork(int V) { this(V, 0, V-1); }

  public void addEdge(int s, int t, double c) {
    maxFlow = null;
    FlowEdge edge = new FlowEdge(s, t, c);
    adj[edge.from()].add(edge);
    adj[edge.to()].add(edge);
  }

  public Iterable<FlowEdge> adj(int v) { return adj[v]; }

  public double maxFlow() {
    edmondsKarp();
    return maxFlow;
  }

  private void edmondsKarp() {
    maxFlow = new Double(0);
    FlowEdge[] parent = new FlowEdge[V];
    Queue<Integer> q = new LinkedList<Integer>();
    while(true) {
      double[] flow = new double[V];
      boolean[] inQueue = new boolean[V];
      flow[s] = Double.POSITIVE_INFINITY;
      inQueue[s] = true;
      q.add(s);
      while(!q.isEmpty()) {
        int u = q.remove();
        inQueue[u] = false;
        for(FlowEdge e : adj[u]) {
          int v = e.other(u);
          if(e.residualCapacityTo(v)>0
              && flow[v]<Math.min(flow[u], e.residualCapacityTo(v))) {
            flow[v] = Math.min(flow[u], e.residualCapacityTo(v));
            if(!inQueue[v]) {
              q.add(v);
              inQueue[v] = true;
            }
            parent[v] = e;
              }
        }
      }
      if(flow[t]==0)
        break;
      for(int u = t; u!=s; u = parent[u].other(u))
        parent[u].addResidualFlowTo(u, flow[t]);
      maxFlow += flow[t];
    }
  }

}

public class POJ3308 {

  public static void main(String[] args) {
    Scanner cin = new Scanner(System.in);
    int nCase = cin.nextInt();
    while((nCase--)!=0) {
      int m = cin.nextInt(), n = cin.nextInt(), l = cin.nextInt();
      FlowNetwork net = new FlowNetwork(m+n+2);
      for(int i = 1; i<=m; i++)
        net.addEdge(0, i, Math.log(cin.nextDouble()));
      for(int i = m+1; i<=m+n; i++)
        net.addEdge(i, m+n+1, Math.log(cin.nextDouble()));
      while((l--)!=0)
        net.addEdge(cin.nextInt(), cin.nextInt()+m, Double.POSITIVE_INFINITY);
      System.out.printf("%.4f\n", Math.exp(net.maxFlow()));
    }
  }

}
