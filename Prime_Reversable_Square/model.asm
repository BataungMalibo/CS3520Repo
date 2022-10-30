.data
input: .asciiz "Enter the range upper bound: "
noResults: .asciiz "No reversal prime squares in the given range"
message1: .asciiz  "Reversal prime squares in the given range are:\n"
.globl main

.text

main:
        jal palindrome
        jal 
	#prompt the user input
	li $v0, 4
	la $a0, input
	syscall 
	
	#get the user input
	li $v0, 5 			#integer input
	syscall
	
	#move the input into the temporary register to allow modification and re-use.
	move $t1, $v0               	#register $t1 stores the maximum number of iterations in the for loop below.
	
	#for loop declaration and initialization
	li $t0, 1           		#Loop counter.
	
	blt $t0, $t1, loop  		#Executes the loop body if $t0 < $t1
	bgt $t0, $t1, end 		#Ends the loop if $t0 > $t1
	
	#Loop body
	loop:
	      li $v0, 4
	      la $a0, message1
	      
	
	
	addi $t0, $t0, 1 		#increment
	j loop 				#jump back to the top to excute the loop body
	end:
	  li $v0, 4
	  la $a0, noResults
	  
	 #terminate program
	  li $v0, 10
	  syscall
	
	 #functions implementations  
	square: 			#squares a number
	
	    li $v0, 5
	    syscall
	    
	   move $t1, $v0
	   
	   mult $t1, $t1
	   mflo $t2
	   add $a0, $zero, $t0
	   jr $ra
	   
	reverse: 			#reverses an integer number.
	  
	  li $t0, 0
	  move $a2, $t0
	  beq $s0, 0, out
	  loop:
	     divu $s0, $t1             #divide number by 10
	     mflo $s0                  #$s0 stores the quotient
	     mfhi $t2                  #$t2 stores reminder
	     mul $a2, $a2, $t1         #reverse=reverse*10
	     addu $a2, $a2, $t2        #reverse=reverse+reminder
	     bne $s0, 0, loop
	    out:
	      move $s0, $a2
	      j li $v0, 10
	      syscall
	   
	    
        palindrome:                    #palindrome checker
             li $v0, 5                 #integer from user input
             syscall
             move $t3, $v0             #the input stored in temporary register
             
             beq $t3, jal reverse, true #if user input(num) equals reverse of num
             bne $t3, jal reverse, false#if user input(num) not equals reverse of num
         
             true:
                addi $v1, $zero, $t3   #$v1 stores and retuns num if it's not a palindrome
             false:
                j palindrome           #jump to the function "palindrome"
                
                
