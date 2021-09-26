package main

import "fmt"
import "C"  // necessary

// The following comment is magic comment. Go will call cgo for this.
//export myfunc_FirstCall
func myfunc_FirstCall() {
    fmt.Println("My function First Call")
}

func main() {}
