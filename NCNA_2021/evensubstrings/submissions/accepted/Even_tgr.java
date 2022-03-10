import java.util.* ;
public class Even_tgr {
   final static int CHUNK = 2048 ;
   static char[] s ;
   static int n ;
   static class chunkdat {
      void update(int ci) {
         for (int i=0; i<64; i++)
            cnts[i] = 0 ;
         int hi = Math.min(n, (ci + 1) * CHUNK) ;
         int v = 0 ;
         for (int i=ci*CHUNK; i<hi; i++) {
            v ^= 1<<(s[i]-'a') ;
            cnts[v]++ ;
         }
         deltamask = v ;
         valid = true ;
      }
      boolean valid ;
      int deltamask ;
      int[] cnts = new int[64] ;
   } ;
   public static void main(String[] args) {
      Scanner sc = new Scanner(System.in) ;
      s = sc.next().toCharArray() ;
      n = s.length ;
      int q = sc.nextInt() ;
      int[] cnts = new int[64] ;
      chunkdat[] chunks = new chunkdat[n/CHUNK+1] ;
      for (int i=0; i<chunks.length; i++)
         chunks[i] = new chunkdat() ;
      while (q-- > 0) {
         int t = sc.nextInt() ;
         if (t == 1) {
            for (int i=0; i<64; i++)
               cnts[i] = 0 ;
            int l = sc.nextInt() ;
            int r = sc.nextInt() ;
            int v = 0 ;
            cnts[0] = 1 ;
            l-- ;
            for (; l < r && l % CHUNK != 0; l++) {
               v ^= 1<<(s[l]-'a') ;
               cnts[v]++ ;
            }
            while (l + CHUNK < r) {
               int ci = l / CHUNK ;
               if (!chunks[ci].valid)
                  chunks[ci].update(ci) ;
               for (int i=0; i<64; i++)
                  cnts[i] += chunks[ci].cnts[i ^ v] ;
               v ^= chunks[ci].deltamask ;
               l += CHUNK ;
            }
            for (; l < r; l++) {
               v ^= 1<<(s[l]-'a') ;
               cnts[v]++ ;
            }
            long rv = 0 ;
            for (int i=0; i<64; i++)
               rv += cnts[i] * (long)(cnts[i]-1) ;
            System.out.println(rv >> 1) ;
         } else {
            int i = sc.nextInt() ;
            char let = sc.next().charAt(0) ;
            s[i-1] = let ;
            chunks[(i-1)/CHUNK].valid = false ;
         }
      }
   }
}
