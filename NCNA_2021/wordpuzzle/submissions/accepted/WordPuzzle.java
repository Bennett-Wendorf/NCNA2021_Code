import java.util.*;
import java.io.*;

public class WordPuzzle {

  final static int M = 1000000007;

  private static Set<String> rotations( String s ) {
    String ss = s + s;
    Set<String> s_rots = new HashSet<String>();
    for( int i = 0; i < s.length(); ++i ) s_rots.add( ss.substring(i, i + s.length()) );
    return s_rots;
  }

  private static long countSubsequences( String p, String w ) {
    int np = p.length();
    int nw = w.length();
    // For l=0..<=np and m=1..<nw,
    // OPT(l,m) is the number of ways, modulo M, that the length-m prefix of w
    // appears as a subsequence of the length-l prefix of p.
    List< List<Integer> > OPT = new ArrayList<List<Integer>>(np+1);
    for( int l = 0; l <= np; ++l ) {
      OPT.add( new ArrayList<Integer>(nw+1) );
      OPT.get(l).add(null); // "m=0" isn't a case we are concerned with
      for( int m = 1; m <= nw; ++m ) {
        OPT.get(l).add(null); // to be computed
      }
    }
    // When l=0, OPT(l,m) = 0 for all m.
    for( int m = 1; m <= nw; ++m ) {
      OPT.get(0).set(m,0);
    }
    // When l > 0 and m = 1, OPT(l,m) counts subsequences of length 1, which
    // are either in an earlier prefix of p (counted by OPT(l-1,m)) or else
    // occur at the end of the prefix of p. Thus
    // OPT(l,m) = { OPT(l-1,m) + 1  if p[l-1] == w[0]
    //            { OPT(l-1,m)      otherwise
    for( int l = 1; l <= np; ++l ) {
      int OPTlm = OPT.get(l-1).get(1);
      if( p.charAt(l-1) == w.charAt(0) ) {
        OPTlm = (OPTlm + 1) % M;
      }
      OPT.get(l).set(1, OPTlm);
    }
    // When l > 0 and m > 1, the subsequences counted by OPT(l,m) either end
    // at the last character of the prefix of p, or belong wholly in a shorter
    // prefix. In the former case, all but the end of the prefix of w is a
    // subsequence of a shorter prefix of p. Thus
    // OPT(l,m) = { OPT(l-1,m) + OPT(l-1,m-1)  if p[l-1] == w[m-1]
    //            { OPT(l-1,m)                 otherwise
    for( int l = 1; l<= np; ++l ) {
      for( int m = 2; m <= nw; ++m ) {
        int OPTlm = OPT.get(l-1).get(m);
        if( p.charAt(l-1) == w.charAt(m-1) ) {
          OPTlm = (OPTlm + OPT.get(l-1).get(m-1)) % M;
        }
        OPT.get(l).set(m, OPTlm);
      }
    }
    // The answer is OPT(np, nw).
    return OPT.get(np).get(nw);
  }

  public static void main(String[] args) {
    Scanner scan = new Scanner( System.in );
    String p = scan.next();
    String s = scan.next();

    Set<String> s_rots = rotations(s);
    long result = 0;
    for( String s_rot : s_rots ) {
      result = (result + countSubsequences(p, s_rot)) % M;
    }
    System.out.println( Long.toString(result) );
  }
}

