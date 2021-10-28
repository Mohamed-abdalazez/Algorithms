import scala.io.StdIn.{readLine, readInt}
import scala.math._
import scala.collection.mutable.ArrayBuffer
import java.io.PrintWriter
import scala.io.Source


object main {
  def main(args:Array[String]) = {

    def binarySearch(arr: Array[Int], target: Int, imin: Int, imax: Int): Int = {
      var start = imax
      var end = imin
      while (start >= end){
        var mid = end + (start - end) / 2
        if(arr(mid) > target)
          start = mid - 1
        else if(arr(mid) < target)
          end = mid + 1
        else 
          return mid
      }
      return -1
    }
    println("Please Enter the size of the array and the target ^_^")
    var n = 0 // size an array
    var tar = 0 // target
    n = readLine.toInt
    tar = readLine.toInt
     println("Please Enter the array elements ^_^")
    val arr = new Array[Int](n) // creat array with size n
    for (i <- 0 to n - 1) // scan an array
      arr(i) = readLine.toInt
    
    /*
    for (i <- 0 to n - 1) // print an array for testing
    print(arr(i) + " ")
    print("\n")
    */

    val check = binarySearch(arr, tar, 0, n - 1)
    //println(check)
    if (check == -1)
      printf("The target doesn't exist :(\n")
    else 
      printf("The target exists in the index %d :)\n", check)
  }
}