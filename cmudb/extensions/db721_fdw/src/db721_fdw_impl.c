// clang-format off
// extern "C" {
#include <unistd.h>
#include <sys/stat.h>
#include <inttypes.h>
#include "db721_fdw_impl.h"
#include "../../../../src/include/postgres.h"
#include "../../../../src/include/fmgr.h"
#include "../../../../src/include/foreign/fdwapi.h"
#include "../../../../src/include/foreign/foreign.h"
#include "../../../../src/include/commands/defrem.h"
// }
// clang-format on

#define METADATA_SIZE_OFFSET 4

/* Reads the given segment from the given file. */
static StringInfo
ReadFromFile(FILE *file, uint64 offset, uint32 size)
{
	int fseekResult = 0;
	int freadResult = 0;
	int fileError = 0;
	StringInfo resultBuffer = makeStringInfo();
	enlargeStringInfo(resultBuffer, size);
	resultBuffer->len = size;
  elog(LOG, "Initialized resultBuffer");
  if (size == 0)
  {
		return resultBuffer;
	}
  elog(LOG, "size was not 0");

	errno = 0;
	fseekResult = fseeko(file, offset, SEEK_SET);
	if (fseekResult != 0)
	{
    elog(LOG, "fseeko failed!");
		ereport(ERROR, (errcode_for_file_access(),
						errmsg("could not seek in file: %m")));
	}
  elog(LOG, "fseeko()ed");

	freadResult = fread(resultBuffer->data, size, 1, file);
	if (freadResult != 1)
	{
		ereport(ERROR, (errmsg("could not read enough data from file")));
	}
  elog(LOG, "fread()ed");

	fileError = ferror(file);
	if (fileError != 0)
	{
		ereport(ERROR, (errcode_for_file_access(),
						errmsg("could not read file: %m")));
	}
  elog(LOG, "ferror was clean");

	return resultBuffer;
}

static char * getFileName(Oid foreignTableId) {
  ForeignTable *foreignTable = GetForeignTable(foreignTableId);
  ListCell *optionCell = NULL;
  char *filename = NULL;
  foreach(optionCell, foreignTable->options) {
    DefElem *def = (DefElem *)lfirst(optionCell);
    if (strcmp(def->defname, "filename") == 0) {
      filename = defGetString(def);
      break;
    }
  }
  return filename;
}

extern void db721_GetForeignRelSize(PlannerInfo *root, RelOptInfo *baserel,
                                    Oid foreigntableid)
{
  char *filename = NULL;
  StringInfo metadataSizeBytes = NULL;
  struct stat stat_buf;
  uint32_t metadataSize = 0;
  FILE *file = NULL;

  // TODO(721): Write me!
  elog(LOG, "db721_GetForeignRelSize called");
  filename = getFileName(foreigntableid);
  elog(LOG, "filename: %s", filename);

  if (stat(filename, &stat_buf) < 0)
  {
    ereport(ERROR, (errcode_for_file_access(),
                    errmsg("could not stat file \"%s\": %m", filename)));
  }
  elog(LOG, "file size: %ld", stat_buf.st_size);

  file = AllocateFile(filename, PG_BINARY_R);
  if (file == NULL)
  {
    ereport(ERROR, (errcode_for_file_access(),
                    errmsg("could not open file \"%s\": %m", filename)));
  }
  elog(LOG, "file opened");
  metadataSizeBytes = ReadFromFile(file, stat_buf.st_size - METADATA_SIZE_OFFSET, METADATA_SIZE_OFFSET);
  elog(LOG, "metadataSizeBytes: %s", metadataSizeBytes->data);
  metadataSize = *((uint32_t *)metadataSizeBytes->data);

  elog(LOG, "metadataSize: %"PRIu32, metadataSize);
  pfree(metadataSizeBytes->data);
  pfree(metadataSizeBytes);
}

extern void db721_GetForeignPaths(PlannerInfo *root, RelOptInfo *baserel,
                                  Oid foreigntableid)
{
  // TODO(721): Write me!
  elog(LOG, "db721_GetForeignPaths called");
}

extern ForeignScan *
db721_GetForeignPlan(PlannerInfo *root, RelOptInfo *baserel, Oid foreigntableid,
                     ForeignPath *best_path, List *tlist, List *scan_clauses,
                     Plan *outer_plan)
{
  // TODO(721): Write me!
  elog(LOG, "db721_GetForeignPlan called");
  return NULL;
}

extern void db721_BeginForeignScan(ForeignScanState *node, int eflags)
{
  // TODO(721): Write me!
  elog(LOG, "db721_BeginForeignScan called");
}

extern TupleTableSlot *db721_IterateForeignScan(ForeignScanState *node)
{
  // TODO(721): Write me!
  elog(LOG, "db721_IterateForeignScan called");
  return NULL;
}

extern void db721_ReScanForeignScan(ForeignScanState *node)
{
  // TODO(721): Write me!
  elog(LOG, "db721_ReScanForeignScan called");
}

extern void db721_EndForeignScan(ForeignScanState *node)
{
  // TODO(721): Write me!
  elog(LOG, "db721_EndForeignScan called");
}