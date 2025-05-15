#include <stdlib.h>
#include <string.h>

typedef struct {
    int timestamp;
    char* value;
} TimeValue;

typedef struct {
    char* key;
    TimeValue* entries;
    int size;
    int capacity;
} TimeEntry;

typedef struct {
    TimeEntry* data;
    int size;
    int capacity;
} TimeMap;

TimeMap* timeMapCreate()
{
    TimeMap* obj = malloc(sizeof(TimeMap));
    obj->size = 0;
    obj->capacity = 16;
    obj->data = malloc(obj->capacity * sizeof(TimeEntry));
    return obj;
}

static void ensureEntryCapacity(TimeEntry* e)
{
    if (e->size >= e->capacity) {
        e->capacity <<= 1;
        e->entries = realloc(e->entries, e->capacity * sizeof(TimeValue));
    }
}


static TimeEntry* findOrCreate(TimeMap* obj, const char* key)
{
    for (int i = 0; i < obj->size; i++) {
        if (strcmp(obj->data[i].key, key) == 0)
            return &obj->data[i];
    }

    if (obj->size >= obj->capacity) {
        obj->capacity <<= 1;
        obj->data = realloc(obj->data, obj->capacity * sizeof(TimeEntry));
    }

    TimeEntry* e = &obj->data[obj->size++];
    e->key      = strdup(key);
    e->size     = 0;
    e->capacity = 8;
    e->entries  = malloc(e->capacity * sizeof(TimeValue));
    return e;
}

void timeMapSet(TimeMap* obj, char* key, char* value, int timestamp)
{
    TimeEntry* e = findOrCreate(obj, key);
    ensureEntryCapacity(e);
    e->entries[e->size].timestamp = timestamp;
    e->entries[e->size].value     = strdup(value);
    e->size++;
}

char* timeMapGet(TimeMap* obj, char* key, int timestamp)
{
    for (int i = 0; i < obj->size; i++) {
        if (strcmp(obj->data[i].key, key) == 0) {
            TimeEntry* e = &obj->data[i];

            int lo = 0, hi = e->size - 1, ans = -1;
            while (lo <= hi) {
                int mid = lo + ((hi - lo) >> 1);
                if (e->entries[mid].timestamp <= timestamp) {
                    ans = mid;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            if (ans != -1) {
                return e->entries[ans].value;
            }
            break;
        }
    }
    return "";
}

void timeMapFree(TimeMap* obj)
{
    for (int i = 0; i < obj->size; i++) {
        TimeEntry* e = &obj->data[i];
        free(e->key);
        for (int j = 0; j < e->size; j++) {
            free(e->entries[j].value);
        }
        free(e->entries);
    }
    free(obj->data);
    free(obj);
}
