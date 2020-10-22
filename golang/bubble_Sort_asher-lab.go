package main
import (
  "fmt"
  )
var items [5]int = [5]int{9,8,7,6,5}

func bubbleSort(passItems [5]int) {
    n := 5
    swapped := true
    for swapped {
        swapped = false
        for i := 1; i < n; i++ {
            if passItems[i-1] > passItems[i] {
                passItems[i], passItems[i-1] = passItems[i-1], passItems[i]
                swapped = true
            }
        }
    }
    fmt.Println(passItems)
}


func main() {
    bubbleSort(items)
}
