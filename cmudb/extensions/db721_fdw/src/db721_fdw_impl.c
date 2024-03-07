// clang-format off
// extern "C" {
#include "db721_fdw_impl.h"
#include "../../../../src/include/postgres.h"
#include "../../../../src/include/fmgr.h"
#include "../../../../src/include/foreign/fdwapi.h"
#include "../../../../src/include/foreign/foreign.h"
#include "../../../../src/include/commands/defrem.h"
// }
// clang-format on

extern void db721_GetForeignRelSize(PlannerInfo *root, RelOptInfo *baserel,
                                    Oid foreigntableid)
{
  ForeignTable *foreignTable = NULL;
  ListCell *optionCell = NULL;
  char *filename = NULL;
  char *tablename = NULL;

  // TODO(721): Write me!
  elog(LOG, "db721_GetForeignRelSize called");

  foreignTable = GetForeignTable(foreigntableid);
  foreach (optionCell, foreignTable->options)
  {
    DefElem *def = (DefElem *)lfirst(optionCell);
    char *optionDefName = def->defname;
    elog(LOG, "option with defname: %s", optionDefName);
    if (strcmp(def->defname, "filename") == 0)
    {
      filename = defGetString(def);
    }
    if (strcmp(def->defname, "tablename") == 0)
    {
      tablename = defGetString(def);
    }
  }
  elog(LOG, "filename: %s", filename);
  elog(LOG, "tablename: %s", tablename);
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