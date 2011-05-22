/* This sample file will run the skip list functions specifications */

#include <stdio.h>

#include "skip_list.h"

#include "skiplist_spec.h"

#include "cspec_output_header.h"
#include "cspec_output_verbose.h"
#include "cspec_output_unit.h"

int main()
{
	CSpecOutputStruct* output = CSpec_NewOutputVerbose();
	
	CSpec_Run( DESCRIPTION( EmptySkipList ), 	output );
	CSpec_Run( DESCRIPTION( SkipListCount ), 	output );
	CSpec_Run( DESCRIPTION( SkipListInsert ), 	output );
	CSpec_Run( DESCRIPTION( SkipListContains ), output );
	CSpec_Run( DESCRIPTION( SkipListDelete ), 	output );

	return 0;
}

