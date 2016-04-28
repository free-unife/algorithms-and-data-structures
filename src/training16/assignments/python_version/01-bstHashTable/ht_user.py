'''
Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
                 Danny Lessio   <danny.lessio@gmail.com>
This work is free. You can redistribute it and/or modify it under the
terms of the Do What The Fuck You Want To Public License, Version 2,
as published by Sam Hocevar. See the LICENSE file for more details.
'''

import hashlib
import random
#value = hashlib.md5( str( key ).encode( 'utf-8' ) ).hexdigest( ) )

class HT_User( object ):
	def __init__( self, hash_table, number_operations, 
		insert_pergentage, search_pergentage, delete_pergentage ):
		
		self._hash_table = hash_table
		self._number_operations = number_operations
		self._insert_pergentage = insert_pergentage / 100
		self._search_pergentage = search_pergentage / 100
		self._delete_pergentage = delete_pergentage / 100
		assert( insert_pergentage + search_pergentage + delete_pergentage == 100 )
		self._total_insertion = 0
		self._total_searches = 0
		self._total_deletion = 0
		self._successfull_insertion = 0
		self._successfull_searches = 0
		self._successfull_deletion = 0


	def __choose_action( self ):
		''' Since random.random() gives a float number between 0 and 1
		    with a normal distribution, we can dicrectly check if 
		    the random number is inside the right interval and TADAaA! '''

		insert_domain = self._insert_pergentage
		search_domain = insert_domain + self._search_pergentage
		delete_domain = search_domain + self._delete_pergentage
		
		x = random.random()
		
		if x <= insert_domain:
			return "insert"
		if x >  insert_domain and x <= search_domain:
			return "search"
		if x >  search_domain and x <= delete_domain:
			return "delete"


	def insert( self ):
		# incremental count of all operations
		self._total_insertion += 1

		try:
			# generate a random key and a random value
			low  = - 10 * self._number_operations
			high =   10 * self._number_operations
			
			key = str( random.randint( low, high ) )
			value = hashlib.md5( str( key ).encode( 'utf-8' ) ).hexdigest()
			
			
			# insert them into the hash table
			self._hash_table.put( key, value )

			# incremental count af all successfull operations
			self._successfull_insertion += 1

		except Exception as e:
			# Doesn't matter if some key falls the insertion
			pass
			


	def search( self ):
		self._total_searches  += 1


	def delete( self ):
		self._total_deletion  += 1


	def begin( self ):
		for operation in range( 0, self._number_operations ):
			operation_type = self.__choose_action()

			if operation_type is "insert":
				self.insert()

			if operation_type is "search":
				self.search()

			if operation_type is "delete":
				self.delete()


	def get_total_insertion( self ):
		return self._total_insertion


	def get_total_searches( self ):
		return self._total_searches


	def get_total_deletion( self ):
		return self._total_deletion

	def get_successfull_insertion( self ):
		return self._successfull_insertion


	def get_successfull_searches( self ):
		return self._successfull_searches


	def get_successfull_deletion( self ):
		return self._successfull_deletion