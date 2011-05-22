
typedef struct skipset SkipSet;

SkipSet* make_skipset();

void delete_skipset(SkipSet* ss);

int contains(SkipSet* ss, int search_value);

int insert(SkipSet* ss, int value);

int delete(SkipSet* ss, int value);

int count(SkipSet* ss);

void print_skipset(SkipSet* ss);
