#include "cspec.h"

#include "skip_list.h"

DESCRIBE(EmptySkipList, "Empty skip list")

	SkipSet* ss = make_skipset();

	IT( "has a count of 0" )
		SHOULD_EQUAL(count(ss), 0)
	END_IT

	IT( "does not contain any value" )
		SHOULD_EQUAL(contains(ss, 0), 0)
		SHOULD_EQUAL(contains(ss, 1), 0)
		SHOULD_EQUAL(contains(ss, 2), 0)
		SHOULD_EQUAL(contains(ss, -1), 0)
	END_IT

	IT( "fails when deleting nodes" )
		SHOULD_EQUAL(delete(ss, 0), 0)
		SHOULD_EQUAL(delete(ss, 2), 0)
		SHOULD_EQUAL(delete(ss, 5), 0)
	END_IT
	
	delete_skipset(ss);

END_DESCRIBE

DESCRIBE(SkipListCount, "count")

	SkipSet* ss = make_skipset();

	IT( "returns 0 when the list is empty" )
		SHOULD_EQUAL(count(ss), 0)
	END_IT

	IT( "returns 1 when one element has been inserted" )
		insert(ss, 0);
		SHOULD_EQUAL(count(ss), 1)
	END_IT

	IT( "returns the number of different elements" )
		insert(ss, 1);
		insert(ss, 2);
		insert(ss, 0);
		SHOULD_EQUAL(count(ss), 3)
	END_IT

	delete_skipset(ss);

END_DESCRIBE

DESCRIBE(SkipListInsert, "insert")

	SkipSet* ss = make_skipset();

	IT( "returns 1 when insertion is successful" )
		SHOULD_EQUAL( insert(ss, 0), 1)
	END_IT

	IT( "returns 0 when insertion failed (item already in the list)" )
		insert(ss, 255);
		SHOULD_EQUAL( insert(ss, 255), 0)
		
		SHOULD_PENDING("check with a more complex list (several levels)")
	END_IT

	delete_skipset(ss);

END_DESCRIBE

DESCRIBE(SkipListContains, "contains")

	SkipSet* ss = make_skipset();

	IT( "returns 1 when the item is found" )
		insert(ss, 45);
		SHOULD_EQUAL( contains(ss, 45), 1)
	END_IT

	IT( "returns 0 when the item is not found" )
		SHOULD_EQUAL( contains(ss, -45), 0)
	END_IT

	delete_skipset(ss);

END_DESCRIBE

DESCRIBE(SkipListDelete, "delete")

	SkipSet* ss = make_skipset();

	IT( "returns 1 when the item is successfully deleted" )
		insert(ss, 45);
		SHOULD_EQUAL( delete(ss, 45), 1)
	END_IT

	IT( "returns 0 when the item is not found" )
		SHOULD_EQUAL( delete(ss, 45), 0)
	END_IT

	delete_skipset(ss);

END_DESCRIBE