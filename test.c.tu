// Program

// Function:
label main

// Local data
//	 Local var (int): c => located at [0]
//	 Local var (int): a => located at [4]
// Load parameters

// Statement
[[BITS32]] load_c 3
natcall vlibc,printf

// Statement
[[BITS32]] load_c 3
[[BITS32]] store 4

// Statement
[[BITS32]] load_c 3
[[BITS32]] load_c 2
[[BITS32]] add
[[BITS32]] load_c 4
call sum
[[BITS32]] store 0

// Function:
label sum

// Local data
//	 Parameter (int): a => located at [0]
//	 Parameter (int): b => located at [4]
// Load parameters
[[BITS32]] store 4
[[BITS32]] store 0

// Statement
[[BITS32]] load_v 0
[[BITS32]] load_v 4
[[BITS32]] add
