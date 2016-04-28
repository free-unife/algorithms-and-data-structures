'''
Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
                 Danny Lessio   <danny.lessio@gmail.com>
This work is free. You can redistribute it and/or modify it under the
terms of the Do What The Fuck You Want To Public License, Version 2,
as published by Sam Hocevar. See the LICENSE file for more details.
'''

import hashlib
import random
from   random import shuffle

class HT_Fake_User( object ):
	def __init__( self, hash_table, number_operations, 
		insert_pergentage, search_pergentage, delete_pergentage ):
		
		self._hash_table = hash_table
		self._number_operations = number_operations
		self._insert_pergentage = insert_pergentage / 100
		self._search_pergentage = search_pergentage / 100
		self._delete_pergentage = delete_pergentage / 100
		assert( insert_pergentage + search_pergentage + delete_pergentage == 100 )
		
		# number of tentatives
		self._total_insert = 0
		self._total_search = 0
		self._total_delete = 0
		
		# successfull tentatives
		self._successfull_insert = 0
		self._successfull_search = 0
		self._successfull_delete = 0
		
		# time variables
		self._insert_time = 0
		self._search_time = 0
		self._delete_time = 0

		# keys inside the HT
		self._keys = []


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
		
		try:
			# get the key
			current_index = self._total_insert
			key = self._keys[ current_index ]

			# generate the value with an md5 applied to the key
			value = hashlib.md5( key.encode( 'utf-8' ) ).hexdigest()
			
			# insert them into the hash table
			self._hash_table.put( key, value )

			# incremental count af all successfull insert
			self._successfull_insert += 1

		except Exception as e:
			# Doesn't matter if some key falls the insertion
			pass

		# incremental count of all operations
		self._total_insert += 1
			


	def search( self ):
		
		try:
			low  = 0
			high = self._number_operations - 1
			random_index = random.randint( low, high )
			random_key = self._keys[ random_index ]
			self._hash_table.get( random_key )
			self._successfull_search += 1
		except:
			# does not matter if a search goes wrong
			pass
		
		self._total_search += 1


	def delete( self ):
		try:
			low  = 0
			high = self._number_operations - 1
			random_index = random.randint( low, high )
			random_key = self._keys[ random_index ]
			self._hash_table.delete( random_key )
			self._successfull_delete += 1
		except:
			# does not matter if a delete goes wrong
			pass

		self._total_delete += 1


	def generate_keys( self ):
		self._keys = []

		low  = - int( self._number_operations / 2 )  
		high =   int( self._number_operations / 2 )
		
		# append in order keys
		for key in range( low, high ):
			self._keys.append( str( key ) )

		# shuffle them
		shuffle( self._keys )


	def start( self ):
		# first generate the keys to push
		self.generate_keys()

		for operation in range( 0, self._number_operations ):
			operation_type = self.__choose_action()

			if operation_type is "insert":
				self.insert()

			if operation_type is "search":
				self.search()

			if operation_type is "delete":
				self.delete()


	def get_total_insert( self ):
		return self._total_insert


	def get_total_search( self ):
		return self._total_search


	def get_total_delete( self ):
		return self._total_delete


	def get_successfull_insert( self ):
		return self._successfull_insert


	def get_successfull_search( self ):
		return self._successfull_search


	def get_successfull_delete( self ):
		return self._successfull_delete


	def get_insert_time( self ):
		return self._insert_time


	def get_search_time( self ):
		return self._search_time


	def get_delete_time( self ):
		return self._delete_time
