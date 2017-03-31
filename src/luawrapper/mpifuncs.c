static int _MPI_Scan(lua_State *L)
{
  void* sendbuf = lua_touserdata(L, 1); luaL_checktype(L, 1, LUA_TUSERDATA);
  void* recvbuf = lua_touserdata(L, 2); luaL_checktype(L, 2, LUA_TUSERDATA);
  int count = luaL_checkinteger(L, 3);
  MPI_Datatype datatype = *((MPI_Datatype*) luaL_checkudata(L, 4, "MPI::Datatype"));
  MPI_Op op = *((MPI_Op*) luaL_checkudata(L, 5, "MPI::Op"));
  MPI_Comm comm = *((MPI_Comm*) luaL_checkudata(L, 6, "MPI::Comm"));
  int res = MPI_Scan(sendbuf, recvbuf, count, datatype, op, comm);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Pack_external_size(lua_State *L)
{
  char* datarep = (char*) lua_touserdata(L, 1); luaL_checktype(L, 1, LUA_TUSERDATA);
  int incount = luaL_checkinteger(L, 2);
  MPI_Datatype datatype = *((MPI_Datatype*) luaL_checkudata(L, 3, "MPI::Datatype"));
  MPI_Aint* size = (MPI_Aint*) luaL_checkudata(L, 4, "MPI::Aint");
  int res = MPI_Pack_external_size(datarep, incount, datatype, size);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Unpack_external(lua_State *L)
{
  char* datarep = (char*) lua_touserdata(L, 1); luaL_checktype(L, 1, LUA_TUSERDATA);
  void* inbuf = lua_touserdata(L, 2); luaL_checktype(L, 2, LUA_TUSERDATA);
  MPI_Aint insize = *((MPI_Aint*) luaL_checkudata(L, 3, "MPI::Aint"));
  MPI_Aint* position = (MPI_Aint*) luaL_checkudata(L, 4, "MPI::Aint");
  void* outbuf = lua_touserdata(L, 5); luaL_checktype(L, 5, LUA_TUSERDATA);
  int outcount = luaL_checkinteger(L, 6);
  MPI_Datatype datatype = *((MPI_Datatype*) luaL_checkudata(L, 7, "MPI::Datatype"));
  int res = MPI_Unpack_external(datarep, inbuf, insize, position, outbuf, outcount, datatype);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Type_create_indexed_block(lua_State *L)
{
  int count = luaL_checkinteger(L, 1);
  int blocklength = luaL_checkinteger(L, 2);
  int* array_of_displacements = (int*) lua_touserdata(L, 3); luaL_checktype(L, 3, LUA_TUSERDATA);
  MPI_Datatype oldtype = *((MPI_Datatype*) luaL_checkudata(L, 4, "MPI::Datatype"));
  MPI_Datatype* newtype = (MPI_Datatype*) luaL_checkudata(L, 5, "MPI::Datatype");
  int res = MPI_Type_create_indexed_block(count, blocklength, array_of_displacements, oldtype, newtype);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Pack_size(lua_State *L)
{
  int incount = luaL_checkinteger(L, 1);
  MPI_Datatype datatype = *((MPI_Datatype*) luaL_checkudata(L, 2, "MPI::Datatype"));
  MPI_Comm comm = *((MPI_Comm*) luaL_checkudata(L, 3, "MPI::Comm"));
  int* size = (int*) lua_touserdata(L, 4); luaL_checktype(L, 4, LUA_TUSERDATA);
  int res = MPI_Pack_size(incount, datatype, comm, size);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Scatterv(lua_State *L)
{
  void* sendbuf = lua_touserdata(L, 1); luaL_checktype(L, 1, LUA_TUSERDATA);
  int* sendcounts = (int*) lua_touserdata(L, 2); luaL_checktype(L, 2, LUA_TUSERDATA);
  int* displs = (int*) lua_touserdata(L, 3); luaL_checktype(L, 3, LUA_TUSERDATA);
  MPI_Datatype sendtype = *((MPI_Datatype*) luaL_checkudata(L, 4, "MPI::Datatype"));
  void* recvbuf = lua_touserdata(L, 5); luaL_checktype(L, 5, LUA_TUSERDATA);
  int recvcount = luaL_checkinteger(L, 6);
  MPI_Datatype recvtype = *((MPI_Datatype*) luaL_checkudata(L, 7, "MPI::Datatype"));
  int root = luaL_checkinteger(L, 8);
  MPI_Comm comm = *((MPI_Comm*) luaL_checkudata(L, 9, "MPI::Comm"));
  int res = MPI_Scatterv(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, root, comm);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Intercomm_merge(lua_State *L)
{
  MPI_Comm intercomm = *((MPI_Comm*) luaL_checkudata(L, 1, "MPI::Comm"));
  int high = luaL_checkinteger(L, 2);
  MPI_Comm* newcomm = (MPI_Comm*) luaL_checkudata(L, 3, "MPI::Comm");
  int res = MPI_Intercomm_merge(intercomm, high, newcomm);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Pack(lua_State *L)
{
  void* inbuf = lua_touserdata(L, 1); luaL_checktype(L, 1, LUA_TUSERDATA);
  int incount = luaL_checkinteger(L, 2);
  MPI_Datatype datatype = *((MPI_Datatype*) luaL_checkudata(L, 3, "MPI::Datatype"));
  void* outbuf = lua_touserdata(L, 4); luaL_checktype(L, 4, LUA_TUSERDATA);
  int outsize = luaL_checkinteger(L, 5);
  int* position = (int*) lua_touserdata(L, 6); luaL_checktype(L, 6, LUA_TUSERDATA);
  MPI_Comm comm = *((MPI_Comm*) luaL_checkudata(L, 7, "MPI::Comm"));
  int res = MPI_Pack(inbuf, incount, datatype, outbuf, outsize, position, comm);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Cart_shift(lua_State *L)
{
  MPI_Comm comm = *((MPI_Comm*) luaL_checkudata(L, 1, "MPI::Comm"));
  int direction = luaL_checkinteger(L, 2);
  int disp = luaL_checkinteger(L, 3);
  int* rank_source = (int*) lua_touserdata(L, 4); luaL_checktype(L, 4, LUA_TUSERDATA);
  int* rank_dest = (int*) lua_touserdata(L, 5); luaL_checktype(L, 5, LUA_TUSERDATA);
  int res = MPI_Cart_shift(comm, direction, disp, rank_source, rank_dest);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_File_read_at_all_end(lua_State *L)
{
  MPI_File fh = *((MPI_File*) luaL_checkudata(L, 1, "MPI::File"));
  void* buf = lua_touserdata(L, 2); luaL_checktype(L, 2, LUA_TUSERDATA);
  MPI_Status* status = (MPI_Status*) luaL_checkudata(L, 3, "MPI::Status");
  int res = MPI_File_read_at_all_end(fh, buf, status);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Group_free(lua_State *L)
{
  MPI_Group* group = (MPI_Group*) luaL_checkudata(L, 1, "MPI::Group");
  int res = MPI_Group_free(group);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_File_set_info(lua_State *L)
{
  MPI_File fh = *((MPI_File*) luaL_checkudata(L, 1, "MPI::File"));
  MPI_Info info = *((MPI_Info*) luaL_checkudata(L, 2, "MPI::Info"));
  int res = MPI_File_set_info(fh, info);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Info_get(lua_State *L)
{
  MPI_Info info = *((MPI_Info*) luaL_checkudata(L, 1, "MPI::Info"));
  char* key = (char*) lua_touserdata(L, 2); luaL_checktype(L, 2, LUA_TUSERDATA);
  int valuelen = luaL_checkinteger(L, 3);
  char* value = (char*) lua_touserdata(L, 4); luaL_checktype(L, 4, LUA_TUSERDATA);
  int* flag = (int*) lua_touserdata(L, 5); luaL_checktype(L, 5, LUA_TUSERDATA);
  int res = MPI_Info_get(info, key, valuelen, value, flag);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Scatter(lua_State *L)
{
  void* sendbuf = lua_touserdata(L, 1); luaL_checktype(L, 1, LUA_TUSERDATA);
  int sendcount = luaL_checkinteger(L, 2);
  MPI_Datatype sendtype = *((MPI_Datatype*) luaL_checkudata(L, 3, "MPI::Datatype"));
  void* recvbuf = lua_touserdata(L, 4); luaL_checktype(L, 4, LUA_TUSERDATA);
  int recvcount = luaL_checkinteger(L, 5);
  MPI_Datatype recvtype = *((MPI_Datatype*) luaL_checkudata(L, 6, "MPI::Datatype"));
  int root = luaL_checkinteger(L, 7);
  MPI_Comm comm = *((MPI_Comm*) luaL_checkudata(L, 8, "MPI::Comm"));
  int res = MPI_Scatter(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Comm_size(lua_State *L)
{
  MPI_Comm comm = *((MPI_Comm*) luaL_checkudata(L, 1, "MPI::Comm"));
  int* size = (int*) lua_touserdata(L, 2); luaL_checktype(L, 2, LUA_TUSERDATA);
  int res = MPI_Comm_size(comm, size);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Test(lua_State *L)
{
  MPI_Request* request = (MPI_Request*) luaL_checkudata(L, 1, "MPI::Request");
  int* completed = (int*) lua_touserdata(L, 2); luaL_checktype(L, 2, LUA_TUSERDATA);
  MPI_Status* status = (MPI_Status*) luaL_checkudata(L, 3, "MPI::Status");
  int res = MPI_Test(request, completed, status);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_File_read_at_all_begin(lua_State *L)
{
  MPI_File fh = *((MPI_File*) luaL_checkudata(L, 1, "MPI::File"));
  MPI_Offset offset = *((MPI_Offset*) luaL_checkudata(L, 2, "MPI::Offset"));
  void* buf = lua_touserdata(L, 3); luaL_checktype(L, 3, LUA_TUSERDATA);
  int count = luaL_checkinteger(L, 4);
  MPI_Datatype datatype = *((MPI_Datatype*) luaL_checkudata(L, 5, "MPI::Datatype"));
  int res = MPI_File_read_at_all_begin(fh, offset, buf, count, datatype);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Recv(lua_State *L)
{
  void* buf = lua_touserdata(L, 1); luaL_checktype(L, 1, LUA_TUSERDATA);
  int count = luaL_checkinteger(L, 2);
  MPI_Datatype type = *((MPI_Datatype*) luaL_checkudata(L, 3, "MPI::Datatype"));
  int source = luaL_checkinteger(L, 4);
  int tag = luaL_checkinteger(L, 5);
  MPI_Comm comm = *((MPI_Comm*) luaL_checkudata(L, 6, "MPI::Comm"));
  MPI_Status* status = (MPI_Status*) luaL_checkudata(L, 7, "MPI::Status");
  int res = MPI_Recv(buf, count, type, source, tag, comm, status);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Win_get_errhandler(lua_State *L)
{
  MPI_Win win = *((MPI_Win*) luaL_checkudata(L, 1, "MPI::Win"));
  MPI_Errhandler* errhandler = (MPI_Errhandler*) luaL_checkudata(L, 2, "MPI::Errhandler");
  int res = MPI_Win_get_errhandler(win, errhandler);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Status_set_elements(lua_State *L)
{
  MPI_Status* status = (MPI_Status*) luaL_checkudata(L, 1, "MPI::Status");
  MPI_Datatype datatype = *((MPI_Datatype*) luaL_checkudata(L, 2, "MPI::Datatype"));
  int count = luaL_checkinteger(L, 3);
  int res = MPI_Status_set_elements(status, datatype, count);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Comm_set_name(lua_State *L)
{
  MPI_Comm comm = *((MPI_Comm*) luaL_checkudata(L, 1, "MPI::Comm"));
  char* name = (char*) lua_touserdata(L, 2); luaL_checktype(L, 2, LUA_TUSERDATA);
  int res = MPI_Comm_set_name(comm, name);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Win_get_group(lua_State *L)
{
  MPI_Win win = *((MPI_Win*) luaL_checkudata(L, 1, "MPI::Win"));
  MPI_Group* group = (MPI_Group*) luaL_checkudata(L, 2, "MPI::Group");
  int res = MPI_Win_get_group(win, group);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_File_seek_shared(lua_State *L)
{
  MPI_File fh = *((MPI_File*) luaL_checkudata(L, 1, "MPI::File"));
  MPI_Offset offset = *((MPI_Offset*) luaL_checkudata(L, 2, "MPI::Offset"));
  int whence = luaL_checkinteger(L, 3);
  int res = MPI_File_seek_shared(fh, offset, whence);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Cart_map(lua_State *L)
{
  MPI_Comm comm = *((MPI_Comm*) luaL_checkudata(L, 1, "MPI::Comm"));
  int ndims = luaL_checkinteger(L, 2);
  int* dims = (int*) lua_touserdata(L, 3); luaL_checktype(L, 3, LUA_TUSERDATA);
  int* periods = (int*) lua_touserdata(L, 4); luaL_checktype(L, 4, LUA_TUSERDATA);
  int* newrank = (int*) lua_touserdata(L, 5); luaL_checktype(L, 5, LUA_TUSERDATA);
  int res = MPI_Cart_map(comm, ndims, dims, periods, newrank);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Win_create_keyval(lua_State *L)
{
  MPI_Win_copy_attr_function* win_copy_attr_fn = (MPI_Win_copy_attr_function*) luaL_checkudata(L, 1, "MPI::Win_copy_attr_function");
  MPI_Win_delete_attr_function* win_delete_attr_fn = (MPI_Win_delete_attr_function*) luaL_checkudata(L, 2, "MPI::Win_delete_attr_function");
  int* win_keyval = (int*) lua_touserdata(L, 3); luaL_checktype(L, 3, LUA_TUSERDATA);
  void* extra_state = lua_touserdata(L, 4); luaL_checktype(L, 4, LUA_TUSERDATA);
  int res = MPI_Win_create_keyval(win_copy_attr_fn, win_delete_attr_fn, win_keyval, extra_state);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Comm_remote_group(lua_State *L)
{
  MPI_Comm comm = *((MPI_Comm*) luaL_checkudata(L, 1, "MPI::Comm"));
  MPI_Group* group = (MPI_Group*) luaL_checkudata(L, 2, "MPI::Group");
  int res = MPI_Comm_remote_group(comm, group);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Win_set_name(lua_State *L)
{
  MPI_Win win = *((MPI_Win*) luaL_checkudata(L, 1, "MPI::Win"));
  char* win_name = (char*) lua_touserdata(L, 2); luaL_checktype(L, 2, LUA_TUSERDATA);
  int res = MPI_Win_set_name(win, win_name);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Info_create(lua_State *L)
{
  MPI_Info* info = (MPI_Info*) luaL_checkudata(L, 1, "MPI::Info");
  int res = MPI_Info_create(info);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Group_translate_ranks(lua_State *L)
{
  MPI_Group group1 = *((MPI_Group*) luaL_checkudata(L, 1, "MPI::Group"));
  int n_ranks = luaL_checkinteger(L, 2);
  int* ranks1 = (int*) lua_touserdata(L, 3); luaL_checktype(L, 3, LUA_TUSERDATA);
  MPI_Group group2 = *((MPI_Group*) luaL_checkudata(L, 4, "MPI::Group"));
  int* ranks2 = (int*) lua_touserdata(L, 5); luaL_checktype(L, 5, LUA_TUSERDATA);
  int res = MPI_Group_translate_ranks(group1, n_ranks, ranks1, group2, ranks2);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Gather(lua_State *L)
{
  void* sendbuf = lua_touserdata(L, 1); luaL_checktype(L, 1, LUA_TUSERDATA);
  int sendcount = luaL_checkinteger(L, 2);
  MPI_Datatype sendtype = *((MPI_Datatype*) luaL_checkudata(L, 3, "MPI::Datatype"));
  void* recvbuf = lua_touserdata(L, 4); luaL_checktype(L, 4, LUA_TUSERDATA);
  int recvcount = luaL_checkinteger(L, 5);
  MPI_Datatype recvtype = *((MPI_Datatype*) luaL_checkudata(L, 6, "MPI::Datatype"));
  int root = luaL_checkinteger(L, 7);
  MPI_Comm comm = *((MPI_Comm*) luaL_checkudata(L, 8, "MPI::Comm"));
  int res = MPI_Gather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Alltoallv(lua_State *L)
{
  void* sendbuf = lua_touserdata(L, 1); luaL_checktype(L, 1, LUA_TUSERDATA);
  int* sendcounts = (int*) lua_touserdata(L, 2); luaL_checktype(L, 2, LUA_TUSERDATA);
  int* sdispls = (int*) lua_touserdata(L, 3); luaL_checktype(L, 3, LUA_TUSERDATA);
  MPI_Datatype sendtype = *((MPI_Datatype*) luaL_checkudata(L, 4, "MPI::Datatype"));
  void* recvbuf = lua_touserdata(L, 5); luaL_checktype(L, 5, LUA_TUSERDATA);
  int* recvcounts = (int*) lua_touserdata(L, 6); luaL_checktype(L, 6, LUA_TUSERDATA);
  int* rdispls = (int*) lua_touserdata(L, 7); luaL_checktype(L, 7, LUA_TUSERDATA);
  MPI_Datatype recvtype = *((MPI_Datatype*) luaL_checkudata(L, 8, "MPI::Datatype"));
  MPI_Comm comm = *((MPI_Comm*) luaL_checkudata(L, 9, "MPI::Comm"));
  int res = MPI_Alltoallv(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Test_cancelled(lua_State *L)
{
  MPI_Status* status = (MPI_Status*) luaL_checkudata(L, 1, "MPI::Status");
  int* flag = (int*) lua_touserdata(L, 2); luaL_checktype(L, 2, LUA_TUSERDATA);
  int res = MPI_Test_cancelled(status, flag);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Cart_get(lua_State *L)
{
  MPI_Comm comm = *((MPI_Comm*) luaL_checkudata(L, 1, "MPI::Comm"));
  int maxdims = luaL_checkinteger(L, 2);
  int* dims = (int*) lua_touserdata(L, 3); luaL_checktype(L, 3, LUA_TUSERDATA);
  int* periods = (int*) lua_touserdata(L, 4); luaL_checktype(L, 4, LUA_TUSERDATA);
  int* coords = (int*) lua_touserdata(L, 5); luaL_checktype(L, 5, LUA_TUSERDATA);
  int res = MPI_Cart_get(comm, maxdims, dims, periods, coords);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Graph_get(lua_State *L)
{
  MPI_Comm comm = *((MPI_Comm*) luaL_checkudata(L, 1, "MPI::Comm"));
  int maxindex = luaL_checkinteger(L, 2);
  int maxedges = luaL_checkinteger(L, 3);
  int* index = (int*) lua_touserdata(L, 4); luaL_checktype(L, 4, LUA_TUSERDATA);
  int* edges = (int*) lua_touserdata(L, 5); luaL_checktype(L, 5, LUA_TUSERDATA);
  int res = MPI_Graph_get(comm, maxindex, maxedges, index, edges);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Type_get_name(lua_State *L)
{
  MPI_Datatype type = *((MPI_Datatype*) luaL_checkudata(L, 1, "MPI::Datatype"));
  char* type_name = (char*) lua_touserdata(L, 2); luaL_checktype(L, 2, LUA_TUSERDATA);
  int* resultlen = (int*) lua_touserdata(L, 3); luaL_checktype(L, 3, LUA_TUSERDATA);
  int res = MPI_Type_get_name(type, type_name, resultlen);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Probe(lua_State *L)
{
  int source = luaL_checkinteger(L, 1);
  int tag = luaL_checkinteger(L, 2);
  MPI_Comm comm = *((MPI_Comm*) luaL_checkudata(L, 3, "MPI::Comm"));
  MPI_Status* status = (MPI_Status*) luaL_checkudata(L, 4, "MPI::Status");
  int res = MPI_Probe(source, tag, comm, status);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Query_thread(lua_State *L)
{
  int* provided = (int*) lua_touserdata(L, 1); luaL_checktype(L, 1, LUA_TUSERDATA);
  int res = MPI_Query_thread(provided);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Comm_call_errhandler(lua_State *L)
{
  MPI_Comm comm = *((MPI_Comm*) luaL_checkudata(L, 1, "MPI::Comm"));
  int errorcode = luaL_checkinteger(L, 2);
  int res = MPI_Comm_call_errhandler(comm, errorcode);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Info_delete(lua_State *L)
{
  MPI_Info info = *((MPI_Info*) luaL_checkudata(L, 1, "MPI::Info"));
  char* key = (char*) lua_touserdata(L, 2); luaL_checktype(L, 2, LUA_TUSERDATA);
  int res = MPI_Info_delete(info, key);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_File_read_all_begin(lua_State *L)
{
  MPI_File fh = *((MPI_File*) luaL_checkudata(L, 1, "MPI::File"));
  void* buf = lua_touserdata(L, 2); luaL_checktype(L, 2, LUA_TUSERDATA);
  int count = luaL_checkinteger(L, 3);
  MPI_Datatype datatype = *((MPI_Datatype*) luaL_checkudata(L, 4, "MPI::Datatype"));
  int res = MPI_File_read_all_begin(fh, buf, count, datatype);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Error_string(lua_State *L)
{
  int errorcode = luaL_checkinteger(L, 1);
  char* string = (char*) lua_touserdata(L, 2); luaL_checktype(L, 2, LUA_TUSERDATA);
  int* resultlen = (int*) lua_touserdata(L, 3); luaL_checktype(L, 3, LUA_TUSERDATA);
  int res = MPI_Error_string(errorcode, string, resultlen);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_File_iread_shared(lua_State *L)
{
  MPI_File fh = *((MPI_File*) luaL_checkudata(L, 1, "MPI::File"));
  void* buf = lua_touserdata(L, 2); luaL_checktype(L, 2, LUA_TUSERDATA);
  int count = luaL_checkinteger(L, 3);
  MPI_Datatype datatype = *((MPI_Datatype*) luaL_checkudata(L, 4, "MPI::Datatype"));
  MPI_Request* request = (MPI_Request*) luaL_checkudata(L, 5, "MPI::Request");
  int res = MPI_File_iread_shared(fh, buf, count, datatype, request);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Alloc_mem(lua_State *L)
{
  MPI_Aint size = *((MPI_Aint*) luaL_checkudata(L, 1, "MPI::Aint"));
  MPI_Info info = *((MPI_Info*) luaL_checkudata(L, 2, "MPI::Info"));
  void* baseptr = lua_touserdata(L, 3); luaL_checktype(L, 3, LUA_TUSERDATA);
  int res = MPI_Alloc_mem(size, info, baseptr);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_File_iwrite_at(lua_State *L)
{
  MPI_File fh = *((MPI_File*) luaL_checkudata(L, 1, "MPI::File"));
  MPI_Offset offset = *((MPI_Offset*) luaL_checkudata(L, 2, "MPI::Offset"));
  void* buf = lua_touserdata(L, 3); luaL_checktype(L, 3, LUA_TUSERDATA);
  int count = luaL_checkinteger(L, 4);
  MPI_Datatype datatype = *((MPI_Datatype*) luaL_checkudata(L, 5, "MPI::Datatype"));
  MPI_Request* request = (MPI_Request*) luaL_checkudata(L, 6, "MPI::Request");
  int res = MPI_File_iwrite_at(fh, offset, buf, count, datatype, request);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_File_seek(lua_State *L)
{
  MPI_File fh = *((MPI_File*) luaL_checkudata(L, 1, "MPI::File"));
  MPI_Offset offset = *((MPI_Offset*) luaL_checkudata(L, 2, "MPI::Offset"));
  int whence = luaL_checkinteger(L, 3);
  int res = MPI_File_seek(fh, offset, whence);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Win_wait(lua_State *L)
{
  MPI_Win win = *((MPI_Win*) luaL_checkudata(L, 1, "MPI::Win"));
  int res = MPI_Win_wait(win);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_File_read_all_end(lua_State *L)
{
  MPI_File fh = *((MPI_File*) luaL_checkudata(L, 1, "MPI::File"));
  void* buf = lua_touserdata(L, 2); luaL_checktype(L, 2, LUA_TUSERDATA);
  MPI_Status* status = (MPI_Status*) luaL_checkudata(L, 3, "MPI::Status");
  int res = MPI_File_read_all_end(fh, buf, status);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_File_get_atomicity(lua_State *L)
{
  MPI_File fh = *((MPI_File*) luaL_checkudata(L, 1, "MPI::File"));
  int* flag = (int*) lua_touserdata(L, 2); luaL_checktype(L, 2, LUA_TUSERDATA);
  int res = MPI_File_get_atomicity(fh, flag);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_File_read_at_all(lua_State *L)
{
  MPI_File fh = *((MPI_File*) luaL_checkudata(L, 1, "MPI::File"));
  MPI_Offset offset = *((MPI_Offset*) luaL_checkudata(L, 2, "MPI::Offset"));
  void* buf = lua_touserdata(L, 3); luaL_checktype(L, 3, LUA_TUSERDATA);
  int count = luaL_checkinteger(L, 4);
  MPI_Datatype datatype = *((MPI_Datatype*) luaL_checkudata(L, 5, "MPI::Datatype"));
  MPI_Status* status = (MPI_Status*) luaL_checkudata(L, 6, "MPI::Status");
  int res = MPI_File_read_at_all(fh, offset, buf, count, datatype, status);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_File_read_ordered(lua_State *L)
{
  MPI_File fh = *((MPI_File*) luaL_checkudata(L, 1, "MPI::File"));
  void* buf = lua_touserdata(L, 2); luaL_checktype(L, 2, LUA_TUSERDATA);
  int count = luaL_checkinteger(L, 3);
  MPI_Datatype datatype = *((MPI_Datatype*) luaL_checkudata(L, 4, "MPI::Datatype"));
  MPI_Status* status = (MPI_Status*) luaL_checkudata(L, 5, "MPI::Status");
  int res = MPI_File_read_ordered(fh, buf, count, datatype, status);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Allreduce(lua_State *L)
{
  void* sendbuf = lua_touserdata(L, 1); luaL_checktype(L, 1, LUA_TUSERDATA);
  void* recvbuf = lua_touserdata(L, 2); luaL_checktype(L, 2, LUA_TUSERDATA);
  int count = luaL_checkinteger(L, 3);
  MPI_Datatype datatype = *((MPI_Datatype*) luaL_checkudata(L, 4, "MPI::Datatype"));
  MPI_Op op = *((MPI_Op*) luaL_checkudata(L, 5, "MPI::Op"));
  MPI_Comm comm = *((MPI_Comm*) luaL_checkudata(L, 6, "MPI::Comm"));
  int res = MPI_Allreduce(sendbuf, recvbuf, count, datatype, op, comm);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Ibsend(lua_State *L)
{
  void* buf = lua_touserdata(L, 1); luaL_checktype(L, 1, LUA_TUSERDATA);
  int count = luaL_checkinteger(L, 2);
  MPI_Datatype type = *((MPI_Datatype*) luaL_checkudata(L, 3, "MPI::Datatype"));
  int dest = luaL_checkinteger(L, 4);
  int tag = luaL_checkinteger(L, 5);
  MPI_Comm comm = *((MPI_Comm*) luaL_checkudata(L, 6, "MPI::Comm"));
  MPI_Request* request = (MPI_Request*) luaL_checkudata(L, 7, "MPI::Request");
  int res = MPI_Ibsend(buf, count, type, dest, tag, comm, request);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Initialized(lua_State *L)
{
  int* flag = (int*) lua_touserdata(L, 1); luaL_checktype(L, 1, LUA_TUSERDATA);
  int res = MPI_Initialized(flag);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Win_start(lua_State *L)
{
  MPI_Group group = *((MPI_Group*) luaL_checkudata(L, 1, "MPI::Group"));
  int assert = luaL_checkinteger(L, 2);
  MPI_Win win = *((MPI_Win*) luaL_checkudata(L, 3, "MPI::Win"));
  int res = MPI_Win_start(group, assert, win);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Grequest_start(lua_State *L)
{
  MPI_Grequest_query_function* query_fn = (MPI_Grequest_query_function*) luaL_checkudata(L, 1, "MPI::Grequest_query_function");
  MPI_Grequest_free_function* free_fn = (MPI_Grequest_free_function*) luaL_checkudata(L, 2, "MPI::Grequest_free_function");
  MPI_Grequest_cancel_function* cancel_fn = (MPI_Grequest_cancel_function*) luaL_checkudata(L, 3, "MPI::Grequest_cancel_function");
  void* extra_state = lua_touserdata(L, 4); luaL_checktype(L, 4, LUA_TUSERDATA);
  MPI_Request* request = (MPI_Request*) luaL_checkudata(L, 5, "MPI::Request");
  int res = MPI_Grequest_start(query_fn, free_fn, cancel_fn, extra_state, request);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Type_create_struct(lua_State *L)
{
  int count = luaL_checkinteger(L, 1);
  int* array_of_blocklengths = (int*) lua_touserdata(L, 2); luaL_checktype(L, 2, LUA_TUSERDATA);
  MPI_Aint* array_of_displacements = (MPI_Aint*) luaL_checkudata(L, 3, "MPI::Aint");
  MPI_Datatype* array_of_types = (MPI_Datatype*) luaL_checkudata(L, 4, "MPI::Datatype");
  MPI_Datatype* newtype = (MPI_Datatype*) luaL_checkudata(L, 5, "MPI::Datatype");
  int res = MPI_Type_create_struct(count, array_of_blocklengths, array_of_displacements, array_of_types, newtype);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Comm_set_attr(lua_State *L)
{
  MPI_Comm comm = *((MPI_Comm*) luaL_checkudata(L, 1, "MPI::Comm"));
  int comm_keyval = luaL_checkinteger(L, 2);
  void* attribute_val = lua_touserdata(L, 3); luaL_checktype(L, 3, LUA_TUSERDATA);
  int res = MPI_Comm_set_attr(comm, comm_keyval, attribute_val);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Comm_delete_attr(lua_State *L)
{
  MPI_Comm comm = *((MPI_Comm*) luaL_checkudata(L, 1, "MPI::Comm"));
  int comm_keyval = luaL_checkinteger(L, 2);
  int res = MPI_Comm_delete_attr(comm, comm_keyval);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_File_get_position(lua_State *L)
{
  MPI_File fh = *((MPI_File*) luaL_checkudata(L, 1, "MPI::File"));
  MPI_Offset* offset = (MPI_Offset*) luaL_checkudata(L, 2, "MPI::Offset");
  int res = MPI_File_get_position(fh, offset);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Group_intersection(lua_State *L)
{
  MPI_Group group1 = *((MPI_Group*) luaL_checkudata(L, 1, "MPI::Group"));
  MPI_Group group2 = *((MPI_Group*) luaL_checkudata(L, 2, "MPI::Group"));
  MPI_Group* new_group = (MPI_Group*) luaL_checkudata(L, 3, "MPI::Group");
  int res = MPI_Group_intersection(group1, group2, new_group);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_File_set_size(lua_State *L)
{
  MPI_File fh = *((MPI_File*) luaL_checkudata(L, 1, "MPI::File"));
  MPI_Offset size = *((MPI_Offset*) luaL_checkudata(L, 2, "MPI::Offset"));
  int res = MPI_File_set_size(fh, size);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Ssend(lua_State *L)
{
  void* buf = lua_touserdata(L, 1); luaL_checktype(L, 1, LUA_TUSERDATA);
  int count = luaL_checkinteger(L, 2);
  MPI_Datatype type = *((MPI_Datatype*) luaL_checkudata(L, 3, "MPI::Datatype"));
  int dest = luaL_checkinteger(L, 4);
  int tag = luaL_checkinteger(L, 5);
  MPI_Comm comm = *((MPI_Comm*) luaL_checkudata(L, 6, "MPI::Comm"));
  int res = MPI_Ssend(buf, count, type, dest, tag, comm);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_File_get_byte_offset(lua_State *L)
{
  MPI_File fh = *((MPI_File*) luaL_checkudata(L, 1, "MPI::File"));
  MPI_Offset offset = *((MPI_Offset*) luaL_checkudata(L, 2, "MPI::Offset"));
  MPI_Offset* disp = (MPI_Offset*) luaL_checkudata(L, 3, "MPI::Offset");
  int res = MPI_File_get_byte_offset(fh, offset, disp);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_File_read_ordered_begin(lua_State *L)
{
  MPI_File fh = *((MPI_File*) luaL_checkudata(L, 1, "MPI::File"));
  void* buf = lua_touserdata(L, 2); luaL_checktype(L, 2, LUA_TUSERDATA);
  int count = luaL_checkinteger(L, 3);
  MPI_Datatype datatype = *((MPI_Datatype*) luaL_checkudata(L, 4, "MPI::Datatype"));
  int res = MPI_File_read_ordered_begin(fh, buf, count, datatype);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Op_free(lua_State *L)
{
  MPI_Op* op = (MPI_Op*) luaL_checkudata(L, 1, "MPI::Op");
  int res = MPI_Op_free(op);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_File_read(lua_State *L)
{
  MPI_File fh = *((MPI_File*) luaL_checkudata(L, 1, "MPI::File"));
  void* buf = lua_touserdata(L, 2); luaL_checktype(L, 2, LUA_TUSERDATA);
  int count = luaL_checkinteger(L, 3);
  MPI_Datatype datatype = *((MPI_Datatype*) luaL_checkudata(L, 4, "MPI::Datatype"));
  MPI_Status* status = (MPI_Status*) luaL_checkudata(L, 5, "MPI::Status");
  int res = MPI_File_read(fh, buf, count, datatype, status);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Send(lua_State *L)
{
  void* buf = lua_touserdata(L, 1); luaL_checktype(L, 1, LUA_TUSERDATA);
  int count = luaL_checkinteger(L, 2);
  MPI_Datatype type = *((MPI_Datatype*) luaL_checkudata(L, 3, "MPI::Datatype"));
  int dest = luaL_checkinteger(L, 4);
  int tag = luaL_checkinteger(L, 5);
  MPI_Comm comm = *((MPI_Comm*) luaL_checkudata(L, 6, "MPI::Comm"));
  int res = MPI_Send(buf, count, type, dest, tag, comm);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Type_get_true_extent(lua_State *L)
{
  MPI_Datatype datatype = *((MPI_Datatype*) luaL_checkudata(L, 1, "MPI::Datatype"));
  MPI_Aint* true_lb = (MPI_Aint*) luaL_checkudata(L, 2, "MPI::Aint");
  MPI_Aint* true_extent = (MPI_Aint*) luaL_checkudata(L, 3, "MPI::Aint");
  int res = MPI_Type_get_true_extent(datatype, true_lb, true_extent);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_File_iread_at(lua_State *L)
{
  MPI_File fh = *((MPI_File*) luaL_checkudata(L, 1, "MPI::File"));
  MPI_Offset offset = *((MPI_Offset*) luaL_checkudata(L, 2, "MPI::Offset"));
  void* buf = lua_touserdata(L, 3); luaL_checktype(L, 3, LUA_TUSERDATA);
  int count = luaL_checkinteger(L, 4);
  MPI_Datatype datatype = *((MPI_Datatype*) luaL_checkudata(L, 5, "MPI::Datatype"));
  MPI_Request* request = (MPI_Request*) luaL_checkudata(L, 6, "MPI::Request");
  int res = MPI_File_iread_at(fh, offset, buf, count, datatype, request);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_File_get_info(lua_State *L)
{
  MPI_File fh = *((MPI_File*) luaL_checkudata(L, 1, "MPI::File"));
  MPI_Info* info_used = (MPI_Info*) luaL_checkudata(L, 2, "MPI::Info");
  int res = MPI_File_get_info(fh, info_used);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Issend(lua_State *L)
{
  void* buf = lua_touserdata(L, 1); luaL_checktype(L, 1, LUA_TUSERDATA);
  int count = luaL_checkinteger(L, 2);
  MPI_Datatype type = *((MPI_Datatype*) luaL_checkudata(L, 3, "MPI::Datatype"));
  int dest = luaL_checkinteger(L, 4);
  int tag = luaL_checkinteger(L, 5);
  MPI_Comm comm = *((MPI_Comm*) luaL_checkudata(L, 6, "MPI::Comm"));
  MPI_Request* request = (MPI_Request*) luaL_checkudata(L, 7, "MPI::Request");
  int res = MPI_Issend(buf, count, type, dest, tag, comm, request);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Finalized(lua_State *L)
{
  int* flag = (int*) lua_touserdata(L, 1); luaL_checktype(L, 1, LUA_TUSERDATA);
  int res = MPI_Finalized(flag);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Alltoall(lua_State *L)
{
  void* sendbuf = lua_touserdata(L, 1); luaL_checktype(L, 1, LUA_TUSERDATA);
  int sendcount = luaL_checkinteger(L, 2);
  MPI_Datatype sendtype = *((MPI_Datatype*) luaL_checkudata(L, 3, "MPI::Datatype"));
  void* recvbuf = lua_touserdata(L, 4); luaL_checktype(L, 4, LUA_TUSERDATA);
  int recvcount = luaL_checkinteger(L, 5);
  MPI_Datatype recvtype = *((MPI_Datatype*) luaL_checkudata(L, 6, "MPI::Datatype"));
  MPI_Comm comm = *((MPI_Comm*) luaL_checkudata(L, 7, "MPI::Comm"));
  int res = MPI_Alltoall(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Publish_name(lua_State *L)
{
  char* service_name = (char*) lua_touserdata(L, 1); luaL_checktype(L, 1, LUA_TUSERDATA);
  MPI_Info info = *((MPI_Info*) luaL_checkudata(L, 2, "MPI::Info"));
  char* port_name = (char*) lua_touserdata(L, 3); luaL_checktype(L, 3, LUA_TUSERDATA);
  int res = MPI_Publish_name(service_name, info, port_name);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_File_get_position_shared(lua_State *L)
{
  MPI_File fh = *((MPI_File*) luaL_checkudata(L, 1, "MPI::File"));
  MPI_Offset* offset = (MPI_Offset*) luaL_checkudata(L, 2, "MPI::Offset");
  int res = MPI_File_get_position_shared(fh, offset);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Type_create_keyval(lua_State *L)
{
  MPI_Type_copy_attr_function* type_copy_attr_fn = (MPI_Type_copy_attr_function*) luaL_checkudata(L, 1, "MPI::Type_copy_attr_function");
  MPI_Type_delete_attr_function* type_delete_attr_fn = (MPI_Type_delete_attr_function*) luaL_checkudata(L, 2, "MPI::Type_delete_attr_function");
  int* type_keyval = (int*) lua_touserdata(L, 3); luaL_checktype(L, 3, LUA_TUSERDATA);
  void* extra_state = lua_touserdata(L, 4); luaL_checktype(L, 4, LUA_TUSERDATA);
  int res = MPI_Type_create_keyval(type_copy_attr_fn, type_delete_attr_fn, type_keyval, extra_state);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Info_set(lua_State *L)
{
  MPI_Info info = *((MPI_Info*) luaL_checkudata(L, 1, "MPI::Info"));
  char* key = (char*) lua_touserdata(L, 2); luaL_checktype(L, 2, LUA_TUSERDATA);
  char* value = (char*) lua_touserdata(L, 3); luaL_checktype(L, 3, LUA_TUSERDATA);
  int res = MPI_Info_set(info, key, value);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_File_open(lua_State *L)
{
  MPI_Comm comm = *((MPI_Comm*) luaL_checkudata(L, 1, "MPI::Comm"));
  char* filename = (char*) lua_touserdata(L, 2); luaL_checktype(L, 2, LUA_TUSERDATA);
  int amode = luaL_checkinteger(L, 3);
  MPI_Info info = *((MPI_Info*) luaL_checkudata(L, 4, "MPI::Info"));
  MPI_File* fh = (MPI_File*) luaL_checkudata(L, 5, "MPI::File");
  int res = MPI_File_open(comm, filename, amode, info, fh);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Wait(lua_State *L)
{
  MPI_Request* request = (MPI_Request*) luaL_checkudata(L, 1, "MPI::Request");
  MPI_Status* status = (MPI_Status*) luaL_checkudata(L, 2, "MPI::Status");
  int res = MPI_Wait(request, status);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Comm_create_keyval(lua_State *L)
{
  MPI_Comm_copy_attr_function* comm_copy_attr_fn = (MPI_Comm_copy_attr_function*) luaL_checkudata(L, 1, "MPI::Comm_copy_attr_function");
  MPI_Comm_delete_attr_function* comm_delete_attr_fn = (MPI_Comm_delete_attr_function*) luaL_checkudata(L, 2, "MPI::Comm_delete_attr_function");
  int* comm_keyval = (int*) lua_touserdata(L, 3); luaL_checktype(L, 3, LUA_TUSERDATA);
  void* extra_state = lua_touserdata(L, 4); luaL_checktype(L, 4, LUA_TUSERDATA);
  int res = MPI_Comm_create_keyval(comm_copy_attr_fn, comm_delete_attr_fn, comm_keyval, extra_state);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_File_write_at_all_end(lua_State *L)
{
  MPI_File fh = *((MPI_File*) luaL_checkudata(L, 1, "MPI::File"));
  void* buf = lua_touserdata(L, 2); luaL_checktype(L, 2, LUA_TUSERDATA);
  MPI_Status* status = (MPI_Status*) luaL_checkudata(L, 3, "MPI::Status");
  int res = MPI_File_write_at_all_end(fh, buf, status);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Win_delete_attr(lua_State *L)
{
  MPI_Win win = *((MPI_Win*) luaL_checkudata(L, 1, "MPI::Win"));
  int win_keyval = luaL_checkinteger(L, 2);
  int res = MPI_Win_delete_attr(win, win_keyval);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Request_free(lua_State *L)
{
  MPI_Request* request = (MPI_Request*) luaL_checkudata(L, 1, "MPI::Request");
  int res = MPI_Request_free(request);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Gatherv(lua_State *L)
{
  void* sendbuf = lua_touserdata(L, 1); luaL_checktype(L, 1, LUA_TUSERDATA);
  int sendcount = luaL_checkinteger(L, 2);
  MPI_Datatype sendtype = *((MPI_Datatype*) luaL_checkudata(L, 3, "MPI::Datatype"));
  void* recvbuf = lua_touserdata(L, 4); luaL_checktype(L, 4, LUA_TUSERDATA);
  int* recvcounts = (int*) lua_touserdata(L, 5); luaL_checktype(L, 5, LUA_TUSERDATA);
  int* displs = (int*) lua_touserdata(L, 6); luaL_checktype(L, 6, LUA_TUSERDATA);
  MPI_Datatype recvtype = *((MPI_Datatype*) luaL_checkudata(L, 7, "MPI::Datatype"));
  int root = luaL_checkinteger(L, 8);
  MPI_Comm comm = *((MPI_Comm*) luaL_checkudata(L, 9, "MPI::Comm"));
  int res = MPI_Gatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, root, comm);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Sendrecv_replace(lua_State *L)
{
  void* buf = lua_touserdata(L, 1); luaL_checktype(L, 1, LUA_TUSERDATA);
  int count = luaL_checkinteger(L, 2);
  MPI_Datatype datatype = *((MPI_Datatype*) luaL_checkudata(L, 3, "MPI::Datatype"));
  int dest = luaL_checkinteger(L, 4);
  int sendtag = luaL_checkinteger(L, 5);
  int source = luaL_checkinteger(L, 6);
  int recvtag = luaL_checkinteger(L, 7);
  MPI_Comm comm = *((MPI_Comm*) luaL_checkudata(L, 8, "MPI::Comm"));
  MPI_Status* status = (MPI_Status*) luaL_checkudata(L, 9, "MPI::Status");
  int res = MPI_Sendrecv_replace(buf, count, datatype, dest, sendtag, source, recvtag, comm, status);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Group_incl(lua_State *L)
{
  MPI_Group group = *((MPI_Group*) luaL_checkudata(L, 1, "MPI::Group"));
  int n = luaL_checkinteger(L, 2);
  int* ranks = (int*) lua_touserdata(L, 3); luaL_checktype(L, 3, LUA_TUSERDATA);
  MPI_Group* new_group = (MPI_Group*) luaL_checkudata(L, 4, "MPI::Group");
  int res = MPI_Group_incl(group, n, ranks, new_group);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Comm_disconnect(lua_State *L)
{
  MPI_Comm* comm = (MPI_Comm*) luaL_checkudata(L, 1, "MPI::Comm");
  int res = MPI_Comm_disconnect(comm);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Reduce_scatter(lua_State *L)
{
  void* sendbuf = lua_touserdata(L, 1); luaL_checktype(L, 1, LUA_TUSERDATA);
  void* recvbuf = lua_touserdata(L, 2); luaL_checktype(L, 2, LUA_TUSERDATA);
  int* recvcounts = (int*) lua_touserdata(L, 3); luaL_checktype(L, 3, LUA_TUSERDATA);
  MPI_Datatype datatype = *((MPI_Datatype*) luaL_checkudata(L, 4, "MPI::Datatype"));
  MPI_Op op = *((MPI_Op*) luaL_checkudata(L, 5, "MPI::Op"));
  MPI_Comm comm = *((MPI_Comm*) luaL_checkudata(L, 6, "MPI::Comm"));
  int res = MPI_Reduce_scatter(sendbuf, recvbuf, recvcounts, datatype, op, comm);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_File_get_view(lua_State *L)
{
  MPI_File fh = *((MPI_File*) luaL_checkudata(L, 1, "MPI::File"));
  MPI_Offset* disp = (MPI_Offset*) luaL_checkudata(L, 2, "MPI::Offset");
  MPI_Datatype* etype = (MPI_Datatype*) luaL_checkudata(L, 3, "MPI::Datatype");
  MPI_Datatype* filetype = (MPI_Datatype*) luaL_checkudata(L, 4, "MPI::Datatype");
  char* datarep = (char*) lua_touserdata(L, 5); luaL_checktype(L, 5, LUA_TUSERDATA);
  int res = MPI_File_get_view(fh, disp, etype, filetype, datarep);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Dims_create(lua_State *L)
{
  int nnodes = luaL_checkinteger(L, 1);
  int ndims = luaL_checkinteger(L, 2);
  int* dims = (int*) lua_touserdata(L, 3); luaL_checktype(L, 3, LUA_TUSERDATA);
  int res = MPI_Dims_create(nnodes, ndims, dims);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Recv_init(lua_State *L)
{
  void* buf = lua_touserdata(L, 1); luaL_checktype(L, 1, LUA_TUSERDATA);
  int count = luaL_checkinteger(L, 2);
  MPI_Datatype type = *((MPI_Datatype*) luaL_checkudata(L, 3, "MPI::Datatype"));
  int source = luaL_checkinteger(L, 4);
  int tag = luaL_checkinteger(L, 5);
  MPI_Comm comm = *((MPI_Comm*) luaL_checkudata(L, 6, "MPI::Comm"));
  MPI_Request* request = (MPI_Request*) luaL_checkudata(L, 7, "MPI::Request");
  int res = MPI_Recv_init(buf, count, type, source, tag, comm, request);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Alltoallw(lua_State *L)
{
  void* sendbuf = lua_touserdata(L, 1); luaL_checktype(L, 1, LUA_TUSERDATA);
  int* sendcounts = (int*) lua_touserdata(L, 2); luaL_checktype(L, 2, LUA_TUSERDATA);
  int* sdispls = (int*) lua_touserdata(L, 3); luaL_checktype(L, 3, LUA_TUSERDATA);
  MPI_Datatype* sendtypes = (MPI_Datatype*) luaL_checkudata(L, 4, "MPI::Datatype");
  void* recvbuf = lua_touserdata(L, 5); luaL_checktype(L, 5, LUA_TUSERDATA);
  int* recvcounts = (int*) lua_touserdata(L, 6); luaL_checktype(L, 6, LUA_TUSERDATA);
  int* rdispls = (int*) lua_touserdata(L, 7); luaL_checktype(L, 7, LUA_TUSERDATA);
  MPI_Datatype* recvtypes = (MPI_Datatype*) luaL_checkudata(L, 8, "MPI::Datatype");
  MPI_Comm comm = *((MPI_Comm*) luaL_checkudata(L, 9, "MPI::Comm"));
  int res = MPI_Alltoallw(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Comm_compare(lua_State *L)
{
  MPI_Comm comm1 = *((MPI_Comm*) luaL_checkudata(L, 1, "MPI::Comm"));
  MPI_Comm comm2 = *((MPI_Comm*) luaL_checkudata(L, 2, "MPI::Comm"));
  int* result = (int*) lua_touserdata(L, 3); luaL_checktype(L, 3, LUA_TUSERDATA);
  int res = MPI_Comm_compare(comm1, comm2, result);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Exscan(lua_State *L)
{
  void* sendbuf = lua_touserdata(L, 1); luaL_checktype(L, 1, LUA_TUSERDATA);
  void* recvbuf = lua_touserdata(L, 2); luaL_checktype(L, 2, LUA_TUSERDATA);
  int count = luaL_checkinteger(L, 3);
  MPI_Datatype datatype = *((MPI_Datatype*) luaL_checkudata(L, 4, "MPI::Datatype"));
  MPI_Op op = *((MPI_Op*) luaL_checkudata(L, 5, "MPI::Op"));
  MPI_Comm comm = *((MPI_Comm*) luaL_checkudata(L, 6, "MPI::Comm"));
  int res = MPI_Exscan(sendbuf, recvbuf, count, datatype, op, comm);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Type_vector(lua_State *L)
{
  int count = luaL_checkinteger(L, 1);
  int blocklength = luaL_checkinteger(L, 2);
  int stride = luaL_checkinteger(L, 3);
  MPI_Datatype oldtype = *((MPI_Datatype*) luaL_checkudata(L, 4, "MPI::Datatype"));
  MPI_Datatype* newtype = (MPI_Datatype*) luaL_checkudata(L, 5, "MPI::Datatype");
  int res = MPI_Type_vector(count, blocklength, stride, oldtype, newtype);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Get_elements(lua_State *L)
{
  MPI_Status* status = (MPI_Status*) luaL_checkudata(L, 1, "MPI::Status");
  MPI_Datatype datatype = *((MPI_Datatype*) luaL_checkudata(L, 2, "MPI::Datatype"));
  int* count = (int*) lua_touserdata(L, 3); luaL_checktype(L, 3, LUA_TUSERDATA);
  int res = MPI_Get_elements(status, datatype, count);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Pack_external(lua_State *L)
{
  char* datarep = (char*) lua_touserdata(L, 1); luaL_checktype(L, 1, LUA_TUSERDATA);
  void* inbuf = lua_touserdata(L, 2); luaL_checktype(L, 2, LUA_TUSERDATA);
  int incount = luaL_checkinteger(L, 3);
  MPI_Datatype datatype = *((MPI_Datatype*) luaL_checkudata(L, 4, "MPI::Datatype"));
  void* outbuf = lua_touserdata(L, 5); luaL_checktype(L, 5, LUA_TUSERDATA);
  MPI_Aint outsize = *((MPI_Aint*) luaL_checkudata(L, 6, "MPI::Aint"));
  MPI_Aint* position = (MPI_Aint*) luaL_checkudata(L, 7, "MPI::Aint");
  int res = MPI_Pack_external(datarep, inbuf, incount, datatype, outbuf, outsize, position);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_File_iwrite_shared(lua_State *L)
{
  MPI_File fh = *((MPI_File*) luaL_checkudata(L, 1, "MPI::File"));
  void* buf = lua_touserdata(L, 2); luaL_checktype(L, 2, LUA_TUSERDATA);
  int count = luaL_checkinteger(L, 3);
  MPI_Datatype datatype = *((MPI_Datatype*) luaL_checkudata(L, 4, "MPI::Datatype"));
  MPI_Request* request = (MPI_Request*) luaL_checkudata(L, 5, "MPI::Request");
  int res = MPI_File_iwrite_shared(fh, buf, count, datatype, request);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Win_get_name(lua_State *L)
{
  MPI_Win win = *((MPI_Win*) luaL_checkudata(L, 1, "MPI::Win"));
  char* win_name = (char*) lua_touserdata(L, 2); luaL_checktype(L, 2, LUA_TUSERDATA);
  int* resultlen = (int*) lua_touserdata(L, 3); luaL_checktype(L, 3, LUA_TUSERDATA);
  int res = MPI_Win_get_name(win, win_name, resultlen);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Info_free(lua_State *L)
{
  MPI_Info* info = (MPI_Info*) luaL_checkudata(L, 1, "MPI::Info");
  int res = MPI_Info_free(info);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Comm_get_parent(lua_State *L)
{
  MPI_Comm* parent = (MPI_Comm*) luaL_checkudata(L, 1, "MPI::Comm");
  int res = MPI_Comm_get_parent(parent);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Group_excl(lua_State *L)
{
  MPI_Group group = *((MPI_Group*) luaL_checkudata(L, 1, "MPI::Group"));
  int n = luaL_checkinteger(L, 2);
  int* ranks = (int*) lua_touserdata(L, 3); luaL_checktype(L, 3, LUA_TUSERDATA);
  MPI_Group* new_group = (MPI_Group*) luaL_checkudata(L, 4, "MPI::Group");
  int res = MPI_Group_excl(group, n, ranks, new_group);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Finalize(lua_State *L)
{
  // no Lua args
  int res = MPI_Finalize();
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Lookup_name(lua_State *L)
{
  char* service_name = (char*) lua_touserdata(L, 1); luaL_checktype(L, 1, LUA_TUSERDATA);
  MPI_Info info = *((MPI_Info*) luaL_checkudata(L, 2, "MPI::Info"));
  char* port_name = (char*) lua_touserdata(L, 3); luaL_checktype(L, 3, LUA_TUSERDATA);
  int res = MPI_Lookup_name(service_name, info, port_name);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Free_mem(lua_State *L)
{
  void* baseptr = lua_touserdata(L, 1); luaL_checktype(L, 1, LUA_TUSERDATA);
  int res = MPI_Free_mem(baseptr);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Win_free_keyval(lua_State *L)
{
  int* win_keyval = (int*) lua_touserdata(L, 1); luaL_checktype(L, 1, LUA_TUSERDATA);
  int res = MPI_Win_free_keyval(win_keyval);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Comm_remote_size(lua_State *L)
{
  MPI_Comm comm = *((MPI_Comm*) luaL_checkudata(L, 1, "MPI::Comm"));
  int* size = (int*) lua_touserdata(L, 2); luaL_checktype(L, 2, LUA_TUSERDATA);
  int res = MPI_Comm_remote_size(comm, size);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Type_create_hvector(lua_State *L)
{
  int count = luaL_checkinteger(L, 1);
  int blocklength = luaL_checkinteger(L, 2);
  MPI_Aint stride = *((MPI_Aint*) luaL_checkudata(L, 3, "MPI::Aint"));
  MPI_Datatype oldtype = *((MPI_Datatype*) luaL_checkudata(L, 4, "MPI::Datatype"));
  MPI_Datatype* newtype = (MPI_Datatype*) luaL_checkudata(L, 5, "MPI::Datatype");
  int res = MPI_Type_create_hvector(count, blocklength, stride, oldtype, newtype);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Cart_rank(lua_State *L)
{
  MPI_Comm comm = *((MPI_Comm*) luaL_checkudata(L, 1, "MPI::Comm"));
  int* coords = (int*) lua_touserdata(L, 2); luaL_checktype(L, 2, LUA_TUSERDATA);
  int* rank = (int*) lua_touserdata(L, 3); luaL_checktype(L, 3, LUA_TUSERDATA);
  int res = MPI_Cart_rank(comm, coords, rank);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Unpack(lua_State *L)
{
  void* inbuf = lua_touserdata(L, 1); luaL_checktype(L, 1, LUA_TUSERDATA);
  int insize = luaL_checkinteger(L, 2);
  int* position = (int*) lua_touserdata(L, 3); luaL_checktype(L, 3, LUA_TUSERDATA);
  void* outbuf = lua_touserdata(L, 4); luaL_checktype(L, 4, LUA_TUSERDATA);
  int outcount = luaL_checkinteger(L, 5);
  MPI_Datatype datatype = *((MPI_Datatype*) luaL_checkudata(L, 6, "MPI::Datatype"));
  MPI_Comm comm = *((MPI_Comm*) luaL_checkudata(L, 7, "MPI::Comm"));
  int res = MPI_Unpack(inbuf, insize, position, outbuf, outcount, datatype, comm);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Status_set_cancelled(lua_State *L)
{
  MPI_Status* status = (MPI_Status*) luaL_checkudata(L, 1, "MPI::Status");
  int flag = luaL_checkinteger(L, 2);
  int res = MPI_Status_set_cancelled(status, flag);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Cartdim_get(lua_State *L)
{
  MPI_Comm comm = *((MPI_Comm*) luaL_checkudata(L, 1, "MPI::Comm"));
  int* ndims = (int*) lua_touserdata(L, 2); luaL_checktype(L, 2, LUA_TUSERDATA);
  int res = MPI_Cartdim_get(comm, ndims);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Win_set_errhandler(lua_State *L)
{
  MPI_Win win = *((MPI_Win*) luaL_checkudata(L, 1, "MPI::Win"));
  MPI_Errhandler errhandler = *((MPI_Errhandler*) luaL_checkudata(L, 2, "MPI::Errhandler"));
  int res = MPI_Win_set_errhandler(win, errhandler);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_File_sync(lua_State *L)
{
  MPI_File fh = *((MPI_File*) luaL_checkudata(L, 1, "MPI::File"));
  int res = MPI_File_sync(fh);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Type_size(lua_State *L)
{
  MPI_Datatype type = *((MPI_Datatype*) luaL_checkudata(L, 1, "MPI::Datatype"));
  int* size = (int*) lua_touserdata(L, 2); luaL_checktype(L, 2, LUA_TUSERDATA);
  int res = MPI_Type_size(type, size);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Allgather(lua_State *L)
{
  void* sendbuf = lua_touserdata(L, 1); luaL_checktype(L, 1, LUA_TUSERDATA);
  int sendcount = luaL_checkinteger(L, 2);
  MPI_Datatype sendtype = *((MPI_Datatype*) luaL_checkudata(L, 3, "MPI::Datatype"));
  void* recvbuf = lua_touserdata(L, 4); luaL_checktype(L, 4, LUA_TUSERDATA);
  int recvcount = luaL_checkinteger(L, 5);
  MPI_Datatype recvtype = *((MPI_Datatype*) luaL_checkudata(L, 6, "MPI::Datatype"));
  MPI_Comm comm = *((MPI_Comm*) luaL_checkudata(L, 7, "MPI::Comm"));
  int res = MPI_Allgather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Comm_rank(lua_State *L)
{
  MPI_Comm comm = *((MPI_Comm*) luaL_checkudata(L, 1, "MPI::Comm"));
  int* rank = (int*) lua_touserdata(L, 2); luaL_checktype(L, 2, LUA_TUSERDATA);
  int res = MPI_Comm_rank(comm, rank);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Register_datarep(lua_State *L)
{
  char* datarep = (char*) lua_touserdata(L, 1); luaL_checktype(L, 1, LUA_TUSERDATA);
  MPI_Datarep_conversion_function* read_conversion_fn = (MPI_Datarep_conversion_function*) luaL_checkudata(L, 2, "MPI::Datarep_conversion_function");
  MPI_Datarep_conversion_function* write_conversion_fn = (MPI_Datarep_conversion_function*) luaL_checkudata(L, 3, "MPI::Datarep_conversion_function");
  MPI_Datarep_extent_function* dtype_file_extent_fn = (MPI_Datarep_extent_function*) luaL_checkudata(L, 4, "MPI::Datarep_extent_function");
  void* extra_state = lua_touserdata(L, 5); luaL_checktype(L, 5, LUA_TUSERDATA);
  int res = MPI_Register_datarep(datarep, read_conversion_fn, write_conversion_fn, dtype_file_extent_fn, extra_state);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Buffer_attach(lua_State *L)
{
  void* buffer = lua_touserdata(L, 1); luaL_checktype(L, 1, LUA_TUSERDATA);
  int size = luaL_checkinteger(L, 2);
  int res = MPI_Buffer_attach(buffer, size);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Win_free(lua_State *L)
{
  MPI_Win* win = (MPI_Win*) luaL_checkudata(L, 1, "MPI::Win");
  int res = MPI_Win_free(win);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Type_set_attr(lua_State *L)
{
  MPI_Datatype type = *((MPI_Datatype*) luaL_checkudata(L, 1, "MPI::Datatype"));
  int type_keyval = luaL_checkinteger(L, 2);
  void* attribute_val = lua_touserdata(L, 3); luaL_checktype(L, 3, LUA_TUSERDATA);
  int res = MPI_Type_set_attr(type, type_keyval, attribute_val);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_File_write_all_begin(lua_State *L)
{
  MPI_File fh = *((MPI_File*) luaL_checkudata(L, 1, "MPI::File"));
  void* buf = lua_touserdata(L, 2); luaL_checktype(L, 2, LUA_TUSERDATA);
  int count = luaL_checkinteger(L, 3);
  MPI_Datatype datatype = *((MPI_Datatype*) luaL_checkudata(L, 4, "MPI::Datatype"));
  int res = MPI_File_write_all_begin(fh, buf, count, datatype);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Info_get_nkeys(lua_State *L)
{
  MPI_Info info = *((MPI_Info*) luaL_checkudata(L, 1, "MPI::Info"));
  int* nkeys = (int*) lua_touserdata(L, 2); luaL_checktype(L, 2, LUA_TUSERDATA);
  int res = MPI_Info_get_nkeys(info, nkeys);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Type_indexed(lua_State *L)
{
  int count = luaL_checkinteger(L, 1);
  int* array_of_blocklengths = (int*) lua_touserdata(L, 2); luaL_checktype(L, 2, LUA_TUSERDATA);
  int* array_of_displacements = (int*) lua_touserdata(L, 3); luaL_checktype(L, 3, LUA_TUSERDATA);
  MPI_Datatype oldtype = *((MPI_Datatype*) luaL_checkudata(L, 4, "MPI::Datatype"));
  MPI_Datatype* newtype = (MPI_Datatype*) luaL_checkudata(L, 5, "MPI::Datatype");
  int res = MPI_Type_indexed(count, array_of_blocklengths, array_of_displacements, oldtype, newtype);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Sendrecv(lua_State *L)
{
  void* sendbuf = lua_touserdata(L, 1); luaL_checktype(L, 1, LUA_TUSERDATA);
  int sendcount = luaL_checkinteger(L, 2);
  MPI_Datatype sendtype = *((MPI_Datatype*) luaL_checkudata(L, 3, "MPI::Datatype"));
  int dest = luaL_checkinteger(L, 4);
  int sendtag = luaL_checkinteger(L, 5);
  void* recvbuf = lua_touserdata(L, 6); luaL_checktype(L, 6, LUA_TUSERDATA);
  int recvcount = luaL_checkinteger(L, 7);
  MPI_Datatype recvtype = *((MPI_Datatype*) luaL_checkudata(L, 8, "MPI::Datatype"));
  int source = luaL_checkinteger(L, 9);
  int recvtag = luaL_checkinteger(L, 10);
  MPI_Comm comm = *((MPI_Comm*) luaL_checkudata(L, 11, "MPI::Comm"));
  MPI_Status* status = (MPI_Status*) luaL_checkudata(L, 12, "MPI::Status");
  int res = MPI_Sendrecv(sendbuf, sendcount, sendtype, dest, sendtag, recvbuf, recvcount, recvtype, source, recvtag, comm, status);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Group_union(lua_State *L)
{
  MPI_Group group1 = *((MPI_Group*) luaL_checkudata(L, 1, "MPI::Group"));
  MPI_Group group2 = *((MPI_Group*) luaL_checkudata(L, 2, "MPI::Group"));
  MPI_Group* new_group = (MPI_Group*) luaL_checkudata(L, 3, "MPI::Group");
  int res = MPI_Group_union(group1, group2, new_group);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_File_iread(lua_State *L)
{
  MPI_File fh = *((MPI_File*) luaL_checkudata(L, 1, "MPI::File"));
  void* buf = lua_touserdata(L, 2); luaL_checktype(L, 2, LUA_TUSERDATA);
  int count = luaL_checkinteger(L, 3);
  MPI_Datatype datatype = *((MPI_Datatype*) luaL_checkudata(L, 4, "MPI::Datatype"));
  MPI_Request* request = (MPI_Request*) luaL_checkudata(L, 5, "MPI::Request");
  int res = MPI_File_iread(fh, buf, count, datatype, request);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Group_size(lua_State *L)
{
  MPI_Group group = *((MPI_Group*) luaL_checkudata(L, 1, "MPI::Group"));
  int* size = (int*) lua_touserdata(L, 2); luaL_checktype(L, 2, LUA_TUSERDATA);
  int res = MPI_Group_size(group, size);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Wtime(lua_State *L)
{
  // no Lua args
  double res = MPI_Wtime();
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_File_delete(lua_State *L)
{
  char* filename = (char*) lua_touserdata(L, 1); luaL_checktype(L, 1, LUA_TUSERDATA);
  MPI_Info info = *((MPI_Info*) luaL_checkudata(L, 2, "MPI::Info"));
  int res = MPI_File_delete(filename, info);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Testall(lua_State *L)
{
  int count = luaL_checkinteger(L, 1);
  MPI_Request* requests = (MPI_Request*) luaL_checkudata(L, 2, "MPI::Request");
  int* flag = (int*) lua_touserdata(L, 3); luaL_checktype(L, 3, LUA_TUSERDATA);
  MPI_Status* statuses = (MPI_Status*) luaL_checkudata(L, 4, "MPI::Status");
  int res = MPI_Testall(count, requests, flag, statuses);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Type_match_size(lua_State *L)
{
  int typeclass = luaL_checkinteger(L, 1);
  int size = luaL_checkinteger(L, 2);
  MPI_Datatype* type = (MPI_Datatype*) luaL_checkudata(L, 3, "MPI::Datatype");
  int res = MPI_Type_match_size(typeclass, size, type);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_File_read_shared(lua_State *L)
{
  MPI_File fh = *((MPI_File*) luaL_checkudata(L, 1, "MPI::File"));
  void* buf = lua_touserdata(L, 2); luaL_checktype(L, 2, LUA_TUSERDATA);
  int count = luaL_checkinteger(L, 3);
  MPI_Datatype datatype = *((MPI_Datatype*) luaL_checkudata(L, 4, "MPI::Datatype"));
  MPI_Status* status = (MPI_Status*) luaL_checkudata(L, 5, "MPI::Status");
  int res = MPI_File_read_shared(fh, buf, count, datatype, status);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Add_error_code(lua_State *L)
{
  int errorclass = luaL_checkinteger(L, 1);
  int* errorcode = (int*) lua_touserdata(L, 2); luaL_checktype(L, 2, LUA_TUSERDATA);
  int res = MPI_Add_error_code(errorclass, errorcode);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Get_version(lua_State *L)
{
  int* version = (int*) lua_touserdata(L, 1); luaL_checktype(L, 1, LUA_TUSERDATA);
  int* subversion = (int*) lua_touserdata(L, 2); luaL_checktype(L, 2, LUA_TUSERDATA);
  int res = MPI_Get_version(version, subversion);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Testsome(lua_State *L)
{
  int incount = luaL_checkinteger(L, 1);
  MPI_Request* requests = (MPI_Request*) luaL_checkudata(L, 2, "MPI::Request");
  int* outcount = (int*) lua_touserdata(L, 3); luaL_checktype(L, 3, LUA_TUSERDATA);
  int* indices = (int*) lua_touserdata(L, 4); luaL_checktype(L, 4, LUA_TUSERDATA);
  MPI_Status* statuses = (MPI_Status*) luaL_checkudata(L, 5, "MPI::Status");
  int res = MPI_Testsome(incount, requests, outcount, indices, statuses);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Reduce(lua_State *L)
{
  void* sendbuf = lua_touserdata(L, 1); luaL_checktype(L, 1, LUA_TUSERDATA);
  void* recvbuf = lua_touserdata(L, 2); luaL_checktype(L, 2, LUA_TUSERDATA);
  int count = luaL_checkinteger(L, 3);
  MPI_Datatype datatype = *((MPI_Datatype*) luaL_checkudata(L, 4, "MPI::Datatype"));
  MPI_Op op = *((MPI_Op*) luaL_checkudata(L, 5, "MPI::Op"));
  int root = luaL_checkinteger(L, 6);
  MPI_Comm comm = *((MPI_Comm*) luaL_checkudata(L, 7, "MPI::Comm"));
  int res = MPI_Reduce(sendbuf, recvbuf, count, datatype, op, root, comm);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Type_dup(lua_State *L)
{
  MPI_Datatype type = *((MPI_Datatype*) luaL_checkudata(L, 1, "MPI::Datatype"));
  MPI_Datatype* newtype = (MPI_Datatype*) luaL_checkudata(L, 2, "MPI::Datatype");
  int res = MPI_Type_dup(type, newtype);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Topo_test(lua_State *L)
{
  MPI_Comm comm = *((MPI_Comm*) luaL_checkudata(L, 1, "MPI::Comm"));
  int* status = (int*) lua_touserdata(L, 2); luaL_checktype(L, 2, LUA_TUSERDATA);
  int res = MPI_Topo_test(comm, status);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Type_get_attr(lua_State *L)
{
  MPI_Datatype type = *((MPI_Datatype*) luaL_checkudata(L, 1, "MPI::Datatype"));
  int type_keyval = luaL_checkinteger(L, 2);
  void* attribute_val = lua_touserdata(L, 3); luaL_checktype(L, 3, LUA_TUSERDATA);
  int* flag = (int*) lua_touserdata(L, 4); luaL_checktype(L, 4, LUA_TUSERDATA);
  int res = MPI_Type_get_attr(type, type_keyval, attribute_val, flag);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Type_get_envelope(lua_State *L)
{
  MPI_Datatype type = *((MPI_Datatype*) luaL_checkudata(L, 1, "MPI::Datatype"));
  int* num_integers = (int*) lua_touserdata(L, 2); luaL_checktype(L, 2, LUA_TUSERDATA);
  int* num_addresses = (int*) lua_touserdata(L, 3); luaL_checktype(L, 3, LUA_TUSERDATA);
  int* num_datatypes = (int*) lua_touserdata(L, 4); luaL_checktype(L, 4, LUA_TUSERDATA);
  int* combiner = (int*) lua_touserdata(L, 5); luaL_checktype(L, 5, LUA_TUSERDATA);
  int res = MPI_Type_get_envelope(type, num_integers, num_addresses, num_datatypes, combiner);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Comm_join(lua_State *L)
{
  int fd = luaL_checkinteger(L, 1);
  MPI_Comm* intercomm = (MPI_Comm*) luaL_checkudata(L, 2, "MPI::Comm");
  int res = MPI_Comm_join(fd, intercomm);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Cart_create(lua_State *L)
{
  MPI_Comm old_comm = *((MPI_Comm*) luaL_checkudata(L, 1, "MPI::Comm"));
  int ndims = luaL_checkinteger(L, 2);
  int* dims = (int*) lua_touserdata(L, 3); luaL_checktype(L, 3, LUA_TUSERDATA);
  int* periods = (int*) lua_touserdata(L, 4); luaL_checktype(L, 4, LUA_TUSERDATA);
  int reorder = luaL_checkinteger(L, 5);
  MPI_Comm* comm_cart = (MPI_Comm*) luaL_checkudata(L, 6, "MPI::Comm");
  int res = MPI_Cart_create(old_comm, ndims, dims, periods, reorder, comm_cart);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_File_write_ordered_begin(lua_State *L)
{
  MPI_File fh = *((MPI_File*) luaL_checkudata(L, 1, "MPI::File"));
  void* buf = lua_touserdata(L, 2); luaL_checktype(L, 2, LUA_TUSERDATA);
  int count = luaL_checkinteger(L, 3);
  MPI_Datatype datatype = *((MPI_Datatype*) luaL_checkudata(L, 4, "MPI::Datatype"));
  int res = MPI_File_write_ordered_begin(fh, buf, count, datatype);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Get_count(lua_State *L)
{
  MPI_Status* status = (MPI_Status*) luaL_checkudata(L, 1, "MPI::Status");
  MPI_Datatype datatype = *((MPI_Datatype*) luaL_checkudata(L, 2, "MPI::Datatype"));
  int* count = (int*) lua_touserdata(L, 3); luaL_checktype(L, 3, LUA_TUSERDATA);
  int res = MPI_Get_count(status, datatype, count);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Irsend(lua_State *L)
{
  void* buf = lua_touserdata(L, 1); luaL_checktype(L, 1, LUA_TUSERDATA);
  int count = luaL_checkinteger(L, 2);
  MPI_Datatype type = *((MPI_Datatype*) luaL_checkudata(L, 3, "MPI::Datatype"));
  int dest = luaL_checkinteger(L, 4);
  int tag = luaL_checkinteger(L, 5);
  MPI_Comm comm = *((MPI_Comm*) luaL_checkudata(L, 6, "MPI::Comm"));
  MPI_Request* request = (MPI_Request*) luaL_checkudata(L, 7, "MPI::Request");
  int res = MPI_Irsend(buf, count, type, dest, tag, comm, request);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Add_error_string(lua_State *L)
{
  int errorcode = luaL_checkinteger(L, 1);
  char* string = (char*) lua_touserdata(L, 2); luaL_checktype(L, 2, LUA_TUSERDATA);
  int res = MPI_Add_error_string(errorcode, string);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Barrier(lua_State *L)
{
  MPI_Comm comm = *((MPI_Comm*) luaL_checkudata(L, 1, "MPI::Comm"));
  int res = MPI_Barrier(comm);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_File_set_view(lua_State *L)
{
  MPI_File fh = *((MPI_File*) luaL_checkudata(L, 1, "MPI::File"));
  MPI_Offset disp = *((MPI_Offset*) luaL_checkudata(L, 2, "MPI::Offset"));
  MPI_Datatype etype = *((MPI_Datatype*) luaL_checkudata(L, 3, "MPI::Datatype"));
  MPI_Datatype filetype = *((MPI_Datatype*) luaL_checkudata(L, 4, "MPI::Datatype"));
  char* datarep = (char*) lua_touserdata(L, 5); luaL_checktype(L, 5, LUA_TUSERDATA);
  MPI_Info info = *((MPI_Info*) luaL_checkudata(L, 6, "MPI::Info"));
  int res = MPI_File_set_view(fh, disp, etype, filetype, datarep, info);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Iprobe(lua_State *L)
{
  int source = luaL_checkinteger(L, 1);
  int tag = luaL_checkinteger(L, 2);
  MPI_Comm comm = *((MPI_Comm*) luaL_checkudata(L, 3, "MPI::Comm"));
  int* flag = (int*) lua_touserdata(L, 4); luaL_checktype(L, 4, LUA_TUSERDATA);
  MPI_Status* status = (MPI_Status*) luaL_checkudata(L, 5, "MPI::Status");
  int res = MPI_Iprobe(source, tag, comm, flag, status);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Unpublish_name(lua_State *L)
{
  char* service_name = (char*) lua_touserdata(L, 1); luaL_checktype(L, 1, LUA_TUSERDATA);
  MPI_Info info = *((MPI_Info*) luaL_checkudata(L, 2, "MPI::Info"));
  char* port_name = (char*) lua_touserdata(L, 3); luaL_checktype(L, 3, LUA_TUSERDATA);
  int res = MPI_Unpublish_name(service_name, info, port_name);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Error_class(lua_State *L)
{
  int errorcode = luaL_checkinteger(L, 1);
  int* errorclass = (int*) lua_touserdata(L, 2); luaL_checktype(L, 2, LUA_TUSERDATA);
  int res = MPI_Error_class(errorcode, errorclass);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Rsend_init(lua_State *L)
{
  void* buf = lua_touserdata(L, 1); luaL_checktype(L, 1, LUA_TUSERDATA);
  int count = luaL_checkinteger(L, 2);
  MPI_Datatype type = *((MPI_Datatype*) luaL_checkudata(L, 3, "MPI::Datatype"));
  int dest = luaL_checkinteger(L, 4);
  int tag = luaL_checkinteger(L, 5);
  MPI_Comm comm = *((MPI_Comm*) luaL_checkudata(L, 6, "MPI::Comm"));
  MPI_Request* request = (MPI_Request*) luaL_checkudata(L, 7, "MPI::Request");
  int res = MPI_Rsend_init(buf, count, type, dest, tag, comm, request);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Type_contiguous(lua_State *L)
{
  int count = luaL_checkinteger(L, 1);
  MPI_Datatype oldtype = *((MPI_Datatype*) luaL_checkudata(L, 2, "MPI::Datatype"));
  MPI_Datatype* newtype = (MPI_Datatype*) luaL_checkudata(L, 3, "MPI::Datatype");
  int res = MPI_Type_contiguous(count, oldtype, newtype);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_File_get_group(lua_State *L)
{
  MPI_File fh = *((MPI_File*) luaL_checkudata(L, 1, "MPI::File"));
  MPI_Group* group = (MPI_Group*) luaL_checkudata(L, 2, "MPI::Group");
  int res = MPI_File_get_group(fh, group);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Waitall(lua_State *L)
{
  int count = luaL_checkinteger(L, 1);
  MPI_Request* requests = (MPI_Request*) luaL_checkudata(L, 2, "MPI::Request");
  MPI_Status* statuses = (MPI_Status*) luaL_checkudata(L, 3, "MPI::Status");
  int res = MPI_Waitall(count, requests, statuses);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Add_error_class(lua_State *L)
{
  int* errorclass = (int*) lua_touserdata(L, 1); luaL_checktype(L, 1, LUA_TUSERDATA);
  int res = MPI_Add_error_class(errorclass);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Win_call_errhandler(lua_State *L)
{
  MPI_Win win = *((MPI_Win*) luaL_checkudata(L, 1, "MPI::Win"));
  int errorcode = luaL_checkinteger(L, 2);
  int res = MPI_Win_call_errhandler(win, errorcode);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Comm_connect(lua_State *L)
{
  char* port_name = (char*) lua_touserdata(L, 1); luaL_checktype(L, 1, LUA_TUSERDATA);
  MPI_Info info = *((MPI_Info*) luaL_checkudata(L, 2, "MPI::Info"));
  int root = luaL_checkinteger(L, 3);
  MPI_Comm comm = *((MPI_Comm*) luaL_checkudata(L, 4, "MPI::Comm"));
  MPI_Comm* newcomm = (MPI_Comm*) luaL_checkudata(L, 5, "MPI::Comm");
  int res = MPI_Comm_connect(port_name, info, root, comm, newcomm);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Errhandler_free(lua_State *L)
{
  MPI_Errhandler* errhandler = (MPI_Errhandler*) luaL_checkudata(L, 1, "MPI::Errhandler");
  int res = MPI_Errhandler_free(errhandler);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Close_port(lua_State *L)
{
  char* port_name = (char*) lua_touserdata(L, 1); luaL_checktype(L, 1, LUA_TUSERDATA);
  int res = MPI_Close_port(port_name);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Comm_test_inter(lua_State *L)
{
  MPI_Comm comm = *((MPI_Comm*) luaL_checkudata(L, 1, "MPI::Comm"));
  int* flag = (int*) lua_touserdata(L, 2); luaL_checktype(L, 2, LUA_TUSERDATA);
  int res = MPI_Comm_test_inter(comm, flag);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_File_write(lua_State *L)
{
  MPI_File fh = *((MPI_File*) luaL_checkudata(L, 1, "MPI::File"));
  void* buf = lua_touserdata(L, 2); luaL_checktype(L, 2, LUA_TUSERDATA);
  int count = luaL_checkinteger(L, 3);
  MPI_Datatype datatype = *((MPI_Datatype*) luaL_checkudata(L, 4, "MPI::Datatype"));
  MPI_Status* status = (MPI_Status*) luaL_checkudata(L, 5, "MPI::Status");
  int res = MPI_File_write(fh, buf, count, datatype, status);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Win_lock(lua_State *L)
{
  int lock_type = luaL_checkinteger(L, 1);
  int rank = luaL_checkinteger(L, 2);
  int assert = luaL_checkinteger(L, 3);
  MPI_Win win = *((MPI_Win*) luaL_checkudata(L, 4, "MPI::Win"));
  int res = MPI_Win_lock(lock_type, rank, assert, win);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Buffer_detach(lua_State *L)
{
  void* buffer = lua_touserdata(L, 1); luaL_checktype(L, 1, LUA_TUSERDATA);
  int* size = (int*) lua_touserdata(L, 2); luaL_checktype(L, 2, LUA_TUSERDATA);
  int res = MPI_Buffer_detach(buffer, size);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Op_create(lua_State *L)
{
  MPI_User_function* function = (MPI_User_function*) luaL_checkudata(L, 1, "MPI::User_function");
  int commute = luaL_checkinteger(L, 2);
  MPI_Op* op = (MPI_Op*) luaL_checkudata(L, 3, "MPI::Op");
  int res = MPI_Op_create(function, commute, op);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Group_rank(lua_State *L)
{
  MPI_Group group = *((MPI_Group*) luaL_checkudata(L, 1, "MPI::Group"));
  int* rank = (int*) lua_touserdata(L, 2); luaL_checktype(L, 2, LUA_TUSERDATA);
  int res = MPI_Group_rank(group, rank);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Graph_create(lua_State *L)
{
  MPI_Comm old_comm = *((MPI_Comm*) luaL_checkudata(L, 1, "MPI::Comm"));
  int nnodes = luaL_checkinteger(L, 2);
  int* index = (int*) lua_touserdata(L, 3); luaL_checktype(L, 3, LUA_TUSERDATA);
  int* edges = (int*) lua_touserdata(L, 4); luaL_checktype(L, 4, LUA_TUSERDATA);
  int reorder = luaL_checkinteger(L, 5);
  MPI_Comm* comm_graph = (MPI_Comm*) luaL_checkudata(L, 6, "MPI::Comm");
  int res = MPI_Graph_create(old_comm, nnodes, index, edges, reorder, comm_graph);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Type_get_contents(lua_State *L)
{
  MPI_Datatype mtype = *((MPI_Datatype*) luaL_checkudata(L, 1, "MPI::Datatype"));
  int max_integers = luaL_checkinteger(L, 2);
  int max_addresses = luaL_checkinteger(L, 3);
  int max_datatypes = luaL_checkinteger(L, 4);
  int* array_of_integers = (int*) lua_touserdata(L, 5); luaL_checktype(L, 5, LUA_TUSERDATA);
  MPI_Aint* array_of_addresses = (MPI_Aint*) luaL_checkudata(L, 6, "MPI::Aint");
  MPI_Datatype* array_of_datatypes = (MPI_Datatype*) luaL_checkudata(L, 7, "MPI::Datatype");
  int res = MPI_Type_get_contents(mtype, max_integers, max_addresses, max_datatypes, array_of_integers, array_of_addresses, array_of_datatypes);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_File_read_at(lua_State *L)
{
  MPI_File fh = *((MPI_File*) luaL_checkudata(L, 1, "MPI::File"));
  MPI_Offset offset = *((MPI_Offset*) luaL_checkudata(L, 2, "MPI::Offset"));
  void* buf = lua_touserdata(L, 3); luaL_checktype(L, 3, LUA_TUSERDATA);
  int count = luaL_checkinteger(L, 4);
  MPI_Datatype datatype = *((MPI_Datatype*) luaL_checkudata(L, 5, "MPI::Datatype"));
  MPI_Status* status = (MPI_Status*) luaL_checkudata(L, 6, "MPI::Status");
  int res = MPI_File_read_at(fh, offset, buf, count, datatype, status);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Comm_free(lua_State *L)
{
  MPI_Comm* comm = (MPI_Comm*) luaL_checkudata(L, 1, "MPI::Comm");
  int res = MPI_Comm_free(comm);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Allgatherv(lua_State *L)
{
  void* sendbuf = lua_touserdata(L, 1); luaL_checktype(L, 1, LUA_TUSERDATA);
  int sendcount = luaL_checkinteger(L, 2);
  MPI_Datatype sendtype = *((MPI_Datatype*) luaL_checkudata(L, 3, "MPI::Datatype"));
  void* recvbuf = lua_touserdata(L, 4); luaL_checktype(L, 4, LUA_TUSERDATA);
  int* recvcounts = (int*) lua_touserdata(L, 5); luaL_checktype(L, 5, LUA_TUSERDATA);
  int* displs = (int*) lua_touserdata(L, 6); luaL_checktype(L, 6, LUA_TUSERDATA);
  MPI_Datatype recvtype = *((MPI_Datatype*) luaL_checkudata(L, 7, "MPI::Datatype"));
  MPI_Comm comm = *((MPI_Comm*) luaL_checkudata(L, 8, "MPI::Comm"));
  int res = MPI_Allgatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Waitsome(lua_State *L)
{
  int incount = luaL_checkinteger(L, 1);
  MPI_Request* requests = (MPI_Request*) luaL_checkudata(L, 2, "MPI::Request");
  int* outcount = (int*) lua_touserdata(L, 3); luaL_checktype(L, 3, LUA_TUSERDATA);
  int* indices = (int*) lua_touserdata(L, 4); luaL_checktype(L, 4, LUA_TUSERDATA);
  MPI_Status* statuses = (MPI_Status*) luaL_checkudata(L, 5, "MPI::Status");
  int res = MPI_Waitsome(incount, requests, outcount, indices, statuses);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Graphdims_get(lua_State *L)
{
  MPI_Comm comm = *((MPI_Comm*) luaL_checkudata(L, 1, "MPI::Comm"));
  int* nnodes = (int*) lua_touserdata(L, 2); luaL_checktype(L, 2, LUA_TUSERDATA);
  int* nedges = (int*) lua_touserdata(L, 3); luaL_checktype(L, 3, LUA_TUSERDATA);
  int res = MPI_Graphdims_get(comm, nnodes, nedges);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Type_free_keyval(lua_State *L)
{
  int* type_keyval = (int*) lua_touserdata(L, 1); luaL_checktype(L, 1, LUA_TUSERDATA);
  int res = MPI_Type_free_keyval(type_keyval);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Send_init(lua_State *L)
{
  void* buf = lua_touserdata(L, 1); luaL_checktype(L, 1, LUA_TUSERDATA);
  int count = luaL_checkinteger(L, 2);
  MPI_Datatype type = *((MPI_Datatype*) luaL_checkudata(L, 3, "MPI::Datatype"));
  int dest = luaL_checkinteger(L, 4);
  int tag = luaL_checkinteger(L, 5);
  MPI_Comm comm = *((MPI_Comm*) luaL_checkudata(L, 6, "MPI::Comm"));
  MPI_Request* request = (MPI_Request*) luaL_checkudata(L, 7, "MPI::Request");
  int res = MPI_Send_init(buf, count, type, dest, tag, comm, request);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_File_close(lua_State *L)
{
  MPI_File* fh = (MPI_File*) luaL_checkudata(L, 1, "MPI::File");
  int res = MPI_File_close(fh);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_File_write_ordered(lua_State *L)
{
  MPI_File fh = *((MPI_File*) luaL_checkudata(L, 1, "MPI::File"));
  void* buf = lua_touserdata(L, 2); luaL_checktype(L, 2, LUA_TUSERDATA);
  int count = luaL_checkinteger(L, 3);
  MPI_Datatype datatype = *((MPI_Datatype*) luaL_checkudata(L, 4, "MPI::Datatype"));
  MPI_Status* status = (MPI_Status*) luaL_checkudata(L, 5, "MPI::Status");
  int res = MPI_File_write_ordered(fh, buf, count, datatype, status);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Rsend(lua_State *L)
{
  void* buf = lua_touserdata(L, 1); luaL_checktype(L, 1, LUA_TUSERDATA);
  int count = luaL_checkinteger(L, 2);
  MPI_Datatype type = *((MPI_Datatype*) luaL_checkudata(L, 3, "MPI::Datatype"));
  int dest = luaL_checkinteger(L, 4);
  int tag = luaL_checkinteger(L, 5);
  MPI_Comm comm = *((MPI_Comm*) luaL_checkudata(L, 6, "MPI::Comm"));
  int res = MPI_Rsend(buf, count, type, dest, tag, comm);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_File_write_shared(lua_State *L)
{
  MPI_File fh = *((MPI_File*) luaL_checkudata(L, 1, "MPI::File"));
  void* buf = lua_touserdata(L, 2); luaL_checktype(L, 2, LUA_TUSERDATA);
  int count = luaL_checkinteger(L, 3);
  MPI_Datatype datatype = *((MPI_Datatype*) luaL_checkudata(L, 4, "MPI::Datatype"));
  MPI_Status* status = (MPI_Status*) luaL_checkudata(L, 5, "MPI::Status");
  int res = MPI_File_write_shared(fh, buf, count, datatype, status);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Wtick(lua_State *L)
{
  // no Lua args
  double res = MPI_Wtick();
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_File_get_type_extent(lua_State *L)
{
  MPI_File fh = *((MPI_File*) luaL_checkudata(L, 1, "MPI::File"));
  MPI_Datatype datatype = *((MPI_Datatype*) luaL_checkudata(L, 2, "MPI::Datatype"));
  MPI_Aint* extent = (MPI_Aint*) luaL_checkudata(L, 3, "MPI::Aint");
  int res = MPI_File_get_type_extent(fh, datatype, extent);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Win_set_attr(lua_State *L)
{
  MPI_Win win = *((MPI_Win*) luaL_checkudata(L, 1, "MPI::Win"));
  int win_keyval = luaL_checkinteger(L, 2);
  void* attribute_val = lua_touserdata(L, 3); luaL_checktype(L, 3, LUA_TUSERDATA);
  int res = MPI_Win_set_attr(win, win_keyval, attribute_val);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Info_dup(lua_State *L)
{
  MPI_Info info = *((MPI_Info*) luaL_checkudata(L, 1, "MPI::Info"));
  MPI_Info* newinfo = (MPI_Info*) luaL_checkudata(L, 2, "MPI::Info");
  int res = MPI_Info_dup(info, newinfo);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Is_thread_main(lua_State *L)
{
  int* flag = (int*) lua_touserdata(L, 1); luaL_checktype(L, 1, LUA_TUSERDATA);
  int res = MPI_Is_thread_main(flag);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Win_fence(lua_State *L)
{
  int assert = luaL_checkinteger(L, 1);
  MPI_Win win = *((MPI_Win*) luaL_checkudata(L, 2, "MPI::Win"));
  int res = MPI_Win_fence(assert, win);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_File_read_all(lua_State *L)
{
  MPI_File fh = *((MPI_File*) luaL_checkudata(L, 1, "MPI::File"));
  void* buf = lua_touserdata(L, 2); luaL_checktype(L, 2, LUA_TUSERDATA);
  int count = luaL_checkinteger(L, 3);
  MPI_Datatype datatype = *((MPI_Datatype*) luaL_checkudata(L, 4, "MPI::Datatype"));
  MPI_Status* status = (MPI_Status*) luaL_checkudata(L, 5, "MPI::Status");
  int res = MPI_File_read_all(fh, buf, count, datatype, status);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Win_unlock(lua_State *L)
{
  int rank = luaL_checkinteger(L, 1);
  MPI_Win win = *((MPI_Win*) luaL_checkudata(L, 2, "MPI::Win"));
  int res = MPI_Win_unlock(rank, win);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Cart_sub(lua_State *L)
{
  MPI_Comm comm = *((MPI_Comm*) luaL_checkudata(L, 1, "MPI::Comm"));
  int* remain_dims = (int*) lua_touserdata(L, 2); luaL_checktype(L, 2, LUA_TUSERDATA);
  MPI_Comm* new_comm = (MPI_Comm*) luaL_checkudata(L, 3, "MPI::Comm");
  int res = MPI_Cart_sub(comm, remain_dims, new_comm);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_File_write_all(lua_State *L)
{
  MPI_File fh = *((MPI_File*) luaL_checkudata(L, 1, "MPI::File"));
  void* buf = lua_touserdata(L, 2); luaL_checktype(L, 2, LUA_TUSERDATA);
  int count = luaL_checkinteger(L, 3);
  MPI_Datatype datatype = *((MPI_Datatype*) luaL_checkudata(L, 4, "MPI::Datatype"));
  MPI_Status* status = (MPI_Status*) luaL_checkudata(L, 5, "MPI::Status");
  int res = MPI_File_write_all(fh, buf, count, datatype, status);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Comm_group(lua_State *L)
{
  MPI_Comm comm = *((MPI_Comm*) luaL_checkudata(L, 1, "MPI::Comm"));
  MPI_Group* group = (MPI_Group*) luaL_checkudata(L, 2, "MPI::Group");
  int res = MPI_Comm_group(comm, group);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_File_write_at_all_begin(lua_State *L)
{
  MPI_File fh = *((MPI_File*) luaL_checkudata(L, 1, "MPI::File"));
  MPI_Offset offset = *((MPI_Offset*) luaL_checkudata(L, 2, "MPI::Offset"));
  void* buf = lua_touserdata(L, 3); luaL_checktype(L, 3, LUA_TUSERDATA);
  int count = luaL_checkinteger(L, 4);
  MPI_Datatype datatype = *((MPI_Datatype*) luaL_checkudata(L, 5, "MPI::Datatype"));
  int res = MPI_File_write_at_all_begin(fh, offset, buf, count, datatype);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Group_compare(lua_State *L)
{
  MPI_Group group1 = *((MPI_Group*) luaL_checkudata(L, 1, "MPI::Group"));
  MPI_Group group2 = *((MPI_Group*) luaL_checkudata(L, 2, "MPI::Group"));
  int* result = (int*) lua_touserdata(L, 3); luaL_checktype(L, 3, LUA_TUSERDATA);
  int res = MPI_Group_compare(group1, group2, result);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Type_get_extent(lua_State *L)
{
  MPI_Datatype type = *((MPI_Datatype*) luaL_checkudata(L, 1, "MPI::Datatype"));
  MPI_Aint* lb = (MPI_Aint*) luaL_checkudata(L, 2, "MPI::Aint");
  MPI_Aint* extent = (MPI_Aint*) luaL_checkudata(L, 3, "MPI::Aint");
  int res = MPI_Type_get_extent(type, lb, extent);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_File_get_amode(lua_State *L)
{
  MPI_File fh = *((MPI_File*) luaL_checkudata(L, 1, "MPI::File"));
  int* amode = (int*) lua_touserdata(L, 2); luaL_checktype(L, 2, LUA_TUSERDATA);
  int res = MPI_File_get_amode(fh, amode);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Type_create_subarray(lua_State *L)
{
  int ndims = luaL_checkinteger(L, 1);
  int* size_array = (int*) lua_touserdata(L, 2); luaL_checktype(L, 2, LUA_TUSERDATA);
  int* subsize_array = (int*) lua_touserdata(L, 3); luaL_checktype(L, 3, LUA_TUSERDATA);
  int* start_array = (int*) lua_touserdata(L, 4); luaL_checktype(L, 4, LUA_TUSERDATA);
  int order = luaL_checkinteger(L, 5);
  MPI_Datatype oldtype = *((MPI_Datatype*) luaL_checkudata(L, 6, "MPI::Datatype"));
  MPI_Datatype* newtype = (MPI_Datatype*) luaL_checkudata(L, 7, "MPI::Datatype");
  int res = MPI_Type_create_subarray(ndims, size_array, subsize_array, start_array, order, oldtype, newtype);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_File_call_errhandler(lua_State *L)
{
  MPI_File fh = *((MPI_File*) luaL_checkudata(L, 1, "MPI::File"));
  int errorcode = luaL_checkinteger(L, 2);
  int res = MPI_File_call_errhandler(fh, errorcode);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Intercomm_create(lua_State *L)
{
  MPI_Comm local_comm = *((MPI_Comm*) luaL_checkudata(L, 1, "MPI::Comm"));
  int local_leader = luaL_checkinteger(L, 2);
  MPI_Comm bridge_comm = *((MPI_Comm*) luaL_checkudata(L, 3, "MPI::Comm"));
  int remote_leader = luaL_checkinteger(L, 4);
  int tag = luaL_checkinteger(L, 5);
  MPI_Comm* newintercomm = (MPI_Comm*) luaL_checkudata(L, 6, "MPI::Comm");
  int res = MPI_Intercomm_create(local_comm, local_leader, bridge_comm, remote_leader, tag, newintercomm);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Type_create_hindexed(lua_State *L)
{
  int count = luaL_checkinteger(L, 1);
  int* array_of_blocklengths = (int*) lua_touserdata(L, 2); luaL_checktype(L, 2, LUA_TUSERDATA);
  MPI_Aint* array_of_displacements = (MPI_Aint*) luaL_checkudata(L, 3, "MPI::Aint");
  MPI_Datatype oldtype = *((MPI_Datatype*) luaL_checkudata(L, 4, "MPI::Datatype"));
  MPI_Datatype* newtype = (MPI_Datatype*) luaL_checkudata(L, 5, "MPI::Datatype");
  int res = MPI_Type_create_hindexed(count, array_of_blocklengths, array_of_displacements, oldtype, newtype);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Graph_map(lua_State *L)
{
  MPI_Comm comm = *((MPI_Comm*) luaL_checkudata(L, 1, "MPI::Comm"));
  int nnodes = luaL_checkinteger(L, 2);
  int* index = (int*) lua_touserdata(L, 3); luaL_checktype(L, 3, LUA_TUSERDATA);
  int* edges = (int*) lua_touserdata(L, 4); luaL_checktype(L, 4, LUA_TUSERDATA);
  int* newrank = (int*) lua_touserdata(L, 5); luaL_checktype(L, 5, LUA_TUSERDATA);
  int res = MPI_Graph_map(comm, nnodes, index, edges, newrank);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Testany(lua_State *L)
{
  int count = luaL_checkinteger(L, 1);
  MPI_Request* requests = (MPI_Request*) luaL_checkudata(L, 2, "MPI::Request");
  int* indx = (int*) lua_touserdata(L, 3); luaL_checktype(L, 3, LUA_TUSERDATA);
  int* completed = (int*) lua_touserdata(L, 4); luaL_checktype(L, 4, LUA_TUSERDATA);
  MPI_Status* status = (MPI_Status*) luaL_checkudata(L, 5, "MPI::Status");
  int res = MPI_Testany(count, requests, indx, completed, status);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Win_test(lua_State *L)
{
  MPI_Win win = *((MPI_Win*) luaL_checkudata(L, 1, "MPI::Win"));
  int* flag = (int*) lua_touserdata(L, 2); luaL_checktype(L, 2, LUA_TUSERDATA);
  int res = MPI_Win_test(win, flag);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Cart_coords(lua_State *L)
{
  MPI_Comm comm = *((MPI_Comm*) luaL_checkudata(L, 1, "MPI::Comm"));
  int rank = luaL_checkinteger(L, 2);
  int maxdims = luaL_checkinteger(L, 3);
  int* coords = (int*) lua_touserdata(L, 4); luaL_checktype(L, 4, LUA_TUSERDATA);
  int res = MPI_Cart_coords(comm, rank, maxdims, coords);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_File_preallocate(lua_State *L)
{
  MPI_File fh = *((MPI_File*) luaL_checkudata(L, 1, "MPI::File"));
  MPI_Offset size = *((MPI_Offset*) luaL_checkudata(L, 2, "MPI::Offset"));
  int res = MPI_File_preallocate(fh, size);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Get_processor_name(lua_State *L)
{
  char* name = (char*) lua_touserdata(L, 1); luaL_checktype(L, 1, LUA_TUSERDATA);
  int* resultlen = (int*) lua_touserdata(L, 2); luaL_checktype(L, 2, LUA_TUSERDATA);
  int res = MPI_Get_processor_name(name, resultlen);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Isend(lua_State *L)
{
  void* buf = lua_touserdata(L, 1); luaL_checktype(L, 1, LUA_TUSERDATA);
  int count = luaL_checkinteger(L, 2);
  MPI_Datatype type = *((MPI_Datatype*) luaL_checkudata(L, 3, "MPI::Datatype"));
  int dest = luaL_checkinteger(L, 4);
  int tag = luaL_checkinteger(L, 5);
  MPI_Comm comm = *((MPI_Comm*) luaL_checkudata(L, 6, "MPI::Comm"));
  MPI_Request* request = (MPI_Request*) luaL_checkudata(L, 7, "MPI::Request");
  int res = MPI_Isend(buf, count, type, dest, tag, comm, request);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Graph_neighbors_count(lua_State *L)
{
  MPI_Comm comm = *((MPI_Comm*) luaL_checkudata(L, 1, "MPI::Comm"));
  int rank = luaL_checkinteger(L, 2);
  int* nneighbors = (int*) lua_touserdata(L, 3); luaL_checktype(L, 3, LUA_TUSERDATA);
  int res = MPI_Graph_neighbors_count(comm, rank, nneighbors);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Comm_get_attr(lua_State *L)
{
  MPI_Comm comm = *((MPI_Comm*) luaL_checkudata(L, 1, "MPI::Comm"));
  int comm_keyval = luaL_checkinteger(L, 2);
  void* attribute_val = lua_touserdata(L, 3); luaL_checktype(L, 3, LUA_TUSERDATA);
  int* flag = (int*) lua_touserdata(L, 4); luaL_checktype(L, 4, LUA_TUSERDATA);
  int res = MPI_Comm_get_attr(comm, comm_keyval, attribute_val, flag);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Open_port(lua_State *L)
{
  MPI_Info info = *((MPI_Info*) luaL_checkudata(L, 1, "MPI::Info"));
  char* port_name = (char*) lua_touserdata(L, 2); luaL_checktype(L, 2, LUA_TUSERDATA);
  int res = MPI_Open_port(info, port_name);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Get(lua_State *L)
{
  void* origin_addr = lua_touserdata(L, 1); luaL_checktype(L, 1, LUA_TUSERDATA);
  int origin_count = luaL_checkinteger(L, 2);
  MPI_Datatype origin_datatype = *((MPI_Datatype*) luaL_checkudata(L, 3, "MPI::Datatype"));
  int target_rank = luaL_checkinteger(L, 4);
  MPI_Aint target_disp = *((MPI_Aint*) luaL_checkudata(L, 5, "MPI::Aint"));
  int target_count = luaL_checkinteger(L, 6);
  MPI_Datatype target_datatype = *((MPI_Datatype*) luaL_checkudata(L, 7, "MPI::Datatype"));
  MPI_Win win = *((MPI_Win*) luaL_checkudata(L, 8, "MPI::Win"));
  int res = MPI_Get(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Bsend(lua_State *L)
{
  void* buf = lua_touserdata(L, 1); luaL_checktype(L, 1, LUA_TUSERDATA);
  int count = luaL_checkinteger(L, 2);
  MPI_Datatype type = *((MPI_Datatype*) luaL_checkudata(L, 3, "MPI::Datatype"));
  int dest = luaL_checkinteger(L, 4);
  int tag = luaL_checkinteger(L, 5);
  MPI_Comm comm = *((MPI_Comm*) luaL_checkudata(L, 6, "MPI::Comm"));
  int res = MPI_Bsend(buf, count, type, dest, tag, comm);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_File_get_size(lua_State *L)
{
  MPI_File fh = *((MPI_File*) luaL_checkudata(L, 1, "MPI::File"));
  MPI_Offset* size = (MPI_Offset*) luaL_checkudata(L, 2, "MPI::Offset");
  int res = MPI_File_get_size(fh, size);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Graph_neighbors(lua_State *L)
{
  MPI_Comm comm = *((MPI_Comm*) luaL_checkudata(L, 1, "MPI::Comm"));
  int rank = luaL_checkinteger(L, 2);
  int maxneighbors = luaL_checkinteger(L, 3);
  int* neighbors = (int*) lua_touserdata(L, 4); luaL_checktype(L, 4, LUA_TUSERDATA);
  int res = MPI_Graph_neighbors(comm, rank, maxneighbors, neighbors);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Type_commit(lua_State *L)
{
  MPI_Datatype* type = (MPI_Datatype*) luaL_checkudata(L, 1, "MPI::Datatype");
  int res = MPI_Type_commit(type);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Irecv(lua_State *L)
{
  void* buf = lua_touserdata(L, 1); luaL_checktype(L, 1, LUA_TUSERDATA);
  int count = luaL_checkinteger(L, 2);
  MPI_Datatype type = *((MPI_Datatype*) luaL_checkudata(L, 3, "MPI::Datatype"));
  int source = luaL_checkinteger(L, 4);
  int tag = luaL_checkinteger(L, 5);
  MPI_Comm comm = *((MPI_Comm*) luaL_checkudata(L, 6, "MPI::Comm"));
  MPI_Request* request = (MPI_Request*) luaL_checkudata(L, 7, "MPI::Request");
  int res = MPI_Irecv(buf, count, type, source, tag, comm, request);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Grequest_complete(lua_State *L)
{
  MPI_Request request = *((MPI_Request*) luaL_checkudata(L, 1, "MPI::Request"));
  int res = MPI_Grequest_complete(request);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Type_delete_attr(lua_State *L)
{
  MPI_Datatype type = *((MPI_Datatype*) luaL_checkudata(L, 1, "MPI::Datatype"));
  int type_keyval = luaL_checkinteger(L, 2);
  int res = MPI_Type_delete_attr(type, type_keyval);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Win_post(lua_State *L)
{
  MPI_Group group = *((MPI_Group*) luaL_checkudata(L, 1, "MPI::Group"));
  int assert = luaL_checkinteger(L, 2);
  MPI_Win win = *((MPI_Win*) luaL_checkudata(L, 3, "MPI::Win"));
  int res = MPI_Win_post(group, assert, win);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Win_get_attr(lua_State *L)
{
  MPI_Win win = *((MPI_Win*) luaL_checkudata(L, 1, "MPI::Win"));
  int win_keyval = luaL_checkinteger(L, 2);
  void* attribute_val = lua_touserdata(L, 3); luaL_checktype(L, 3, LUA_TUSERDATA);
  int* flag = (int*) lua_touserdata(L, 4); luaL_checktype(L, 4, LUA_TUSERDATA);
  int res = MPI_Win_get_attr(win, win_keyval, attribute_val, flag);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Get_address(lua_State *L)
{
  void* location = lua_touserdata(L, 1); luaL_checktype(L, 1, LUA_TUSERDATA);
  MPI_Aint* address = (MPI_Aint*) luaL_checkudata(L, 2, "MPI::Aint");
  int res = MPI_Get_address(location, address);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Comm_accept(lua_State *L)
{
  char* port_name = (char*) lua_touserdata(L, 1); luaL_checktype(L, 1, LUA_TUSERDATA);
  MPI_Info info = *((MPI_Info*) luaL_checkudata(L, 2, "MPI::Info"));
  int root = luaL_checkinteger(L, 3);
  MPI_Comm comm = *((MPI_Comm*) luaL_checkudata(L, 4, "MPI::Comm"));
  MPI_Comm* newcomm = (MPI_Comm*) luaL_checkudata(L, 5, "MPI::Comm");
  int res = MPI_Comm_accept(port_name, info, root, comm, newcomm);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Bsend_init(lua_State *L)
{
  void* buf = lua_touserdata(L, 1); luaL_checktype(L, 1, LUA_TUSERDATA);
  int count = luaL_checkinteger(L, 2);
  MPI_Datatype type = *((MPI_Datatype*) luaL_checkudata(L, 3, "MPI::Datatype"));
  int dest = luaL_checkinteger(L, 4);
  int tag = luaL_checkinteger(L, 5);
  MPI_Comm comm = *((MPI_Comm*) luaL_checkudata(L, 6, "MPI::Comm"));
  MPI_Request* request = (MPI_Request*) luaL_checkudata(L, 7, "MPI::Request");
  int res = MPI_Bsend_init(buf, count, type, dest, tag, comm, request);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Comm_free_keyval(lua_State *L)
{
  int* comm_keyval = (int*) lua_touserdata(L, 1); luaL_checktype(L, 1, LUA_TUSERDATA);
  int res = MPI_Comm_free_keyval(comm_keyval);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Put(lua_State *L)
{
  void* origin_addr = lua_touserdata(L, 1); luaL_checktype(L, 1, LUA_TUSERDATA);
  int origin_count = luaL_checkinteger(L, 2);
  MPI_Datatype origin_datatype = *((MPI_Datatype*) luaL_checkudata(L, 3, "MPI::Datatype"));
  int target_rank = luaL_checkinteger(L, 4);
  MPI_Aint target_disp = *((MPI_Aint*) luaL_checkudata(L, 5, "MPI::Aint"));
  int target_count = luaL_checkinteger(L, 6);
  MPI_Datatype target_datatype = *((MPI_Datatype*) luaL_checkudata(L, 7, "MPI::Datatype"));
  MPI_Win win = *((MPI_Win*) luaL_checkudata(L, 8, "MPI::Win"));
  int res = MPI_Put(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Accumulate(lua_State *L)
{
  void* origin_addr = lua_touserdata(L, 1); luaL_checktype(L, 1, LUA_TUSERDATA);
  int origin_count = luaL_checkinteger(L, 2);
  MPI_Datatype origin_datatype = *((MPI_Datatype*) luaL_checkudata(L, 3, "MPI::Datatype"));
  int target_rank = luaL_checkinteger(L, 4);
  MPI_Aint target_disp = *((MPI_Aint*) luaL_checkudata(L, 5, "MPI::Aint"));
  int target_count = luaL_checkinteger(L, 6);
  MPI_Datatype target_datatype = *((MPI_Datatype*) luaL_checkudata(L, 7, "MPI::Datatype"));
  MPI_Op op = *((MPI_Op*) luaL_checkudata(L, 8, "MPI::Op"));
  MPI_Win win = *((MPI_Win*) luaL_checkudata(L, 9, "MPI::Win"));
  int res = MPI_Accumulate(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, op, win);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Info_get_nthkey(lua_State *L)
{
  MPI_Info info = *((MPI_Info*) luaL_checkudata(L, 1, "MPI::Info"));
  int n = luaL_checkinteger(L, 2);
  char* key = (char*) lua_touserdata(L, 3); luaL_checktype(L, 3, LUA_TUSERDATA);
  int res = MPI_Info_get_nthkey(info, n, key);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Comm_create(lua_State *L)
{
  MPI_Comm comm = *((MPI_Comm*) luaL_checkudata(L, 1, "MPI::Comm"));
  MPI_Group group = *((MPI_Group*) luaL_checkudata(L, 2, "MPI::Group"));
  MPI_Comm* newcomm = (MPI_Comm*) luaL_checkudata(L, 3, "MPI::Comm");
  int res = MPI_Comm_create(comm, group, newcomm);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Comm_set_errhandler(lua_State *L)
{
  MPI_Comm comm = *((MPI_Comm*) luaL_checkudata(L, 1, "MPI::Comm"));
  MPI_Errhandler errhandler = *((MPI_Errhandler*) luaL_checkudata(L, 2, "MPI::Errhandler"));
  int res = MPI_Comm_set_errhandler(comm, errhandler);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_File_write_at_all(lua_State *L)
{
  MPI_File fh = *((MPI_File*) luaL_checkudata(L, 1, "MPI::File"));
  MPI_Offset offset = *((MPI_Offset*) luaL_checkudata(L, 2, "MPI::Offset"));
  void* buf = lua_touserdata(L, 3); luaL_checktype(L, 3, LUA_TUSERDATA);
  int count = luaL_checkinteger(L, 4);
  MPI_Datatype datatype = *((MPI_Datatype*) luaL_checkudata(L, 5, "MPI::Datatype"));
  MPI_Status* status = (MPI_Status*) luaL_checkudata(L, 6, "MPI::Status");
  int res = MPI_File_write_at_all(fh, offset, buf, count, datatype, status);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Type_create_resized(lua_State *L)
{
  MPI_Datatype oldtype = *((MPI_Datatype*) luaL_checkudata(L, 1, "MPI::Datatype"));
  MPI_Aint lb = *((MPI_Aint*) luaL_checkudata(L, 2, "MPI::Aint"));
  MPI_Aint extent = *((MPI_Aint*) luaL_checkudata(L, 3, "MPI::Aint"));
  MPI_Datatype* newtype = (MPI_Datatype*) luaL_checkudata(L, 4, "MPI::Datatype");
  int res = MPI_Type_create_resized(oldtype, lb, extent, newtype);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Cancel(lua_State *L)
{
  MPI_Request* request = (MPI_Request*) luaL_checkudata(L, 1, "MPI::Request");
  int res = MPI_Cancel(request);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Abort(lua_State *L)
{
  MPI_Comm comm = *((MPI_Comm*) luaL_checkudata(L, 1, "MPI::Comm"));
  int errorcode = luaL_checkinteger(L, 2);
  int res = MPI_Abort(comm, errorcode);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_File_set_atomicity(lua_State *L)
{
  MPI_File fh = *((MPI_File*) luaL_checkudata(L, 1, "MPI::File"));
  int flag = luaL_checkinteger(L, 2);
  int res = MPI_File_set_atomicity(fh, flag);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Comm_get_name(lua_State *L)
{
  MPI_Comm comm = *((MPI_Comm*) luaL_checkudata(L, 1, "MPI::Comm"));
  char* name = (char*) lua_touserdata(L, 2); luaL_checktype(L, 2, LUA_TUSERDATA);
  int* length = (int*) lua_touserdata(L, 3); luaL_checktype(L, 3, LUA_TUSERDATA);
  int res = MPI_Comm_get_name(comm, name, length);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_File_write_at(lua_State *L)
{
  MPI_File fh = *((MPI_File*) luaL_checkudata(L, 1, "MPI::File"));
  MPI_Offset offset = *((MPI_Offset*) luaL_checkudata(L, 2, "MPI::Offset"));
  void* buf = lua_touserdata(L, 3); luaL_checktype(L, 3, LUA_TUSERDATA);
  int count = luaL_checkinteger(L, 4);
  MPI_Datatype datatype = *((MPI_Datatype*) luaL_checkudata(L, 5, "MPI::Datatype"));
  MPI_Status* status = (MPI_Status*) luaL_checkudata(L, 6, "MPI::Status");
  int res = MPI_File_write_at(fh, offset, buf, count, datatype, status);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Startall(lua_State *L)
{
  int count = luaL_checkinteger(L, 1);
  MPI_Request* requests = (MPI_Request*) luaL_checkudata(L, 2, "MPI::Request");
  int res = MPI_Startall(count, requests);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Comm_split(lua_State *L)
{
  MPI_Comm comm = *((MPI_Comm*) luaL_checkudata(L, 1, "MPI::Comm"));
  int color = luaL_checkinteger(L, 2);
  int key = luaL_checkinteger(L, 3);
  MPI_Comm* newcomm = (MPI_Comm*) luaL_checkudata(L, 4, "MPI::Comm");
  int res = MPI_Comm_split(comm, color, key, newcomm);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Type_create_darray(lua_State *L)
{
  int size = luaL_checkinteger(L, 1);
  int rank = luaL_checkinteger(L, 2);
  int ndims = luaL_checkinteger(L, 3);
  int* gsize_array = (int*) lua_touserdata(L, 4); luaL_checktype(L, 4, LUA_TUSERDATA);
  int* distrib_array = (int*) lua_touserdata(L, 5); luaL_checktype(L, 5, LUA_TUSERDATA);
  int* darg_array = (int*) lua_touserdata(L, 6); luaL_checktype(L, 6, LUA_TUSERDATA);
  int* psize_array = (int*) lua_touserdata(L, 7); luaL_checktype(L, 7, LUA_TUSERDATA);
  int order = luaL_checkinteger(L, 8);
  MPI_Datatype oldtype = *((MPI_Datatype*) luaL_checkudata(L, 9, "MPI::Datatype"));
  MPI_Datatype* newtype = (MPI_Datatype*) luaL_checkudata(L, 10, "MPI::Datatype");
  int res = MPI_Type_create_darray(size, rank, ndims, gsize_array, distrib_array, darg_array, psize_array, order, oldtype, newtype);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Start(lua_State *L)
{
  MPI_Request* request = (MPI_Request*) luaL_checkudata(L, 1, "MPI::Request");
  int res = MPI_Start(request);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Group_difference(lua_State *L)
{
  MPI_Group group1 = *((MPI_Group*) luaL_checkudata(L, 1, "MPI::Group"));
  MPI_Group group2 = *((MPI_Group*) luaL_checkudata(L, 2, "MPI::Group"));
  MPI_Group* new_group = (MPI_Group*) luaL_checkudata(L, 3, "MPI::Group");
  int res = MPI_Group_difference(group1, group2, new_group);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Type_free(lua_State *L)
{
  MPI_Datatype* type = (MPI_Datatype*) luaL_checkudata(L, 1, "MPI::Datatype");
  int res = MPI_Type_free(type);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Info_get_valuelen(lua_State *L)
{
  MPI_Info info = *((MPI_Info*) luaL_checkudata(L, 1, "MPI::Info"));
  char* key = (char*) lua_touserdata(L, 2); luaL_checktype(L, 2, LUA_TUSERDATA);
  int* valuelen = (int*) lua_touserdata(L, 3); luaL_checktype(L, 3, LUA_TUSERDATA);
  int* flag = (int*) lua_touserdata(L, 4); luaL_checktype(L, 4, LUA_TUSERDATA);
  int res = MPI_Info_get_valuelen(info, key, valuelen, flag);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_File_write_ordered_end(lua_State *L)
{
  MPI_File fh = *((MPI_File*) luaL_checkudata(L, 1, "MPI::File"));
  void* buf = lua_touserdata(L, 2); luaL_checktype(L, 2, LUA_TUSERDATA);
  MPI_Status* status = (MPI_Status*) luaL_checkudata(L, 3, "MPI::Status");
  int res = MPI_File_write_ordered_end(fh, buf, status);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_File_get_errhandler(lua_State *L)
{
  MPI_File file = *((MPI_File*) luaL_checkudata(L, 1, "MPI::File"));
  MPI_Errhandler* errhandler = (MPI_Errhandler*) luaL_checkudata(L, 2, "MPI::Errhandler");
  int res = MPI_File_get_errhandler(file, errhandler);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Win_create(lua_State *L)
{
  void* base = lua_touserdata(L, 1); luaL_checktype(L, 1, LUA_TUSERDATA);
  MPI_Aint size = *((MPI_Aint*) luaL_checkudata(L, 2, "MPI::Aint"));
  int disp_unit = luaL_checkinteger(L, 3);
  MPI_Info info = *((MPI_Info*) luaL_checkudata(L, 4, "MPI::Info"));
  MPI_Comm comm = *((MPI_Comm*) luaL_checkudata(L, 5, "MPI::Comm"));
  MPI_Win* win = (MPI_Win*) luaL_checkudata(L, 6, "MPI::Win");
  int res = MPI_Win_create(base, size, disp_unit, info, comm, win);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Type_set_name(lua_State *L)
{
  MPI_Datatype type = *((MPI_Datatype*) luaL_checkudata(L, 1, "MPI::Datatype"));
  char* type_name = (char*) lua_touserdata(L, 2); luaL_checktype(L, 2, LUA_TUSERDATA);
  int res = MPI_Type_set_name(type, type_name);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Comm_get_errhandler(lua_State *L)
{
  MPI_Comm comm = *((MPI_Comm*) luaL_checkudata(L, 1, "MPI::Comm"));
  MPI_Errhandler* errhandler = (MPI_Errhandler*) luaL_checkudata(L, 2, "MPI::Errhandler");
  int res = MPI_Comm_get_errhandler(comm, errhandler);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Waitany(lua_State *L)
{
  int count = luaL_checkinteger(L, 1);
  MPI_Request* requests = (MPI_Request*) luaL_checkudata(L, 2, "MPI::Request");
  int* indx = (int*) lua_touserdata(L, 3); luaL_checktype(L, 3, LUA_TUSERDATA);
  MPI_Status* status = (MPI_Status*) luaL_checkudata(L, 4, "MPI::Status");
  int res = MPI_Waitany(count, requests, indx, status);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Win_complete(lua_State *L)
{
  MPI_Win win = *((MPI_Win*) luaL_checkudata(L, 1, "MPI::Win"));
  int res = MPI_Win_complete(win);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_File_read_ordered_end(lua_State *L)
{
  MPI_File fh = *((MPI_File*) luaL_checkudata(L, 1, "MPI::File"));
  void* buf = lua_touserdata(L, 2); luaL_checktype(L, 2, LUA_TUSERDATA);
  MPI_Status* status = (MPI_Status*) luaL_checkudata(L, 3, "MPI::Status");
  int res = MPI_File_read_ordered_end(fh, buf, status);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Bcast(lua_State *L)
{
  void* buffer = lua_touserdata(L, 1); luaL_checktype(L, 1, LUA_TUSERDATA);
  int count = luaL_checkinteger(L, 2);
  MPI_Datatype datatype = *((MPI_Datatype*) luaL_checkudata(L, 3, "MPI::Datatype"));
  int root = luaL_checkinteger(L, 4);
  MPI_Comm comm = *((MPI_Comm*) luaL_checkudata(L, 5, "MPI::Comm"));
  int res = MPI_Bcast(buffer, count, datatype, root, comm);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_File_write_all_end(lua_State *L)
{
  MPI_File fh = *((MPI_File*) luaL_checkudata(L, 1, "MPI::File"));
  void* buf = lua_touserdata(L, 2); luaL_checktype(L, 2, LUA_TUSERDATA);
  MPI_Status* status = (MPI_Status*) luaL_checkudata(L, 3, "MPI::Status");
  int res = MPI_File_write_all_end(fh, buf, status);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Ssend_init(lua_State *L)
{
  void* buf = lua_touserdata(L, 1); luaL_checktype(L, 1, LUA_TUSERDATA);
  int count = luaL_checkinteger(L, 2);
  MPI_Datatype type = *((MPI_Datatype*) luaL_checkudata(L, 3, "MPI::Datatype"));
  int dest = luaL_checkinteger(L, 4);
  int tag = luaL_checkinteger(L, 5);
  MPI_Comm comm = *((MPI_Comm*) luaL_checkudata(L, 6, "MPI::Comm"));
  MPI_Request* request = (MPI_Request*) luaL_checkudata(L, 7, "MPI::Request");
  int res = MPI_Ssend_init(buf, count, type, dest, tag, comm, request);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Request_get_status(lua_State *L)
{
  MPI_Request request = *((MPI_Request*) luaL_checkudata(L, 1, "MPI::Request"));
  int* flag = (int*) lua_touserdata(L, 2); luaL_checktype(L, 2, LUA_TUSERDATA);
  MPI_Status* status = (MPI_Status*) luaL_checkudata(L, 3, "MPI::Status");
  int res = MPI_Request_get_status(request, flag, status);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_File_iwrite(lua_State *L)
{
  MPI_File fh = *((MPI_File*) luaL_checkudata(L, 1, "MPI::File"));
  void* buf = lua_touserdata(L, 2); luaL_checktype(L, 2, LUA_TUSERDATA);
  int count = luaL_checkinteger(L, 3);
  MPI_Datatype datatype = *((MPI_Datatype*) luaL_checkudata(L, 4, "MPI::Datatype"));
  MPI_Request* request = (MPI_Request*) luaL_checkudata(L, 5, "MPI::Request");
  int res = MPI_File_iwrite(fh, buf, count, datatype, request);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_File_set_errhandler(lua_State *L)
{
  MPI_File file = *((MPI_File*) luaL_checkudata(L, 1, "MPI::File"));
  MPI_Errhandler errhandler = *((MPI_Errhandler*) luaL_checkudata(L, 2, "MPI::Errhandler"));
  int res = MPI_File_set_errhandler(file, errhandler);
  lua_pushnumber(L, res);
  return 1;
}
static int _MPI_Comm_dup(lua_State *L)
{
  MPI_Comm comm = *((MPI_Comm*) luaL_checkudata(L, 1, "MPI::Comm"));
  MPI_Comm* newcomm = (MPI_Comm*) luaL_checkudata(L, 2, "MPI::Comm");
  int res = MPI_Comm_dup(comm, newcomm);
  lua_pushnumber(L, res);
  return 1;
}
luaL_Reg MPI_module_funcs[] = {
  { "Scan", _MPI_Scan},
  { "Pack_external_size", _MPI_Pack_external_size},
  { "Unpack_external", _MPI_Unpack_external},
  { "Type_create_indexed_block", _MPI_Type_create_indexed_block},
  { "Pack_size", _MPI_Pack_size},
  { "Scatterv", _MPI_Scatterv},
  { "Intercomm_merge", _MPI_Intercomm_merge},
  { "Pack", _MPI_Pack},
  { "Cart_shift", _MPI_Cart_shift},
  { "File_read_at_all_end", _MPI_File_read_at_all_end},
  { "Group_free", _MPI_Group_free},
  { "File_set_info", _MPI_File_set_info},
  { "Info_get", _MPI_Info_get},
  { "Scatter", _MPI_Scatter},
  { "Comm_size", _MPI_Comm_size},
  { "Test", _MPI_Test},
  { "File_read_at_all_begin", _MPI_File_read_at_all_begin},
  { "Recv", _MPI_Recv},
  { "Win_get_errhandler", _MPI_Win_get_errhandler},
  { "Status_set_elements", _MPI_Status_set_elements},
  { "Comm_set_name", _MPI_Comm_set_name},
  { "Win_get_group", _MPI_Win_get_group},
  { "File_seek_shared", _MPI_File_seek_shared},
  { "Cart_map", _MPI_Cart_map},
  { "Win_create_keyval", _MPI_Win_create_keyval},
  { "Comm_remote_group", _MPI_Comm_remote_group},
  { "Win_set_name", _MPI_Win_set_name},
  { "Info_create", _MPI_Info_create},
  { "Group_translate_ranks", _MPI_Group_translate_ranks},
  { "Gather", _MPI_Gather},
  { "Alltoallv", _MPI_Alltoallv},
  { "Test_cancelled", _MPI_Test_cancelled},
  { "Cart_get", _MPI_Cart_get},
  { "Graph_get", _MPI_Graph_get},
  { "Type_get_name", _MPI_Type_get_name},
  { "Probe", _MPI_Probe},
  { "Query_thread", _MPI_Query_thread},
  { "Comm_call_errhandler", _MPI_Comm_call_errhandler},
  { "Info_delete", _MPI_Info_delete},
  { "File_read_all_begin", _MPI_File_read_all_begin},
  { "Error_string", _MPI_Error_string},
  { "File_iread_shared", _MPI_File_iread_shared},
  { "Alloc_mem", _MPI_Alloc_mem},
  { "File_iwrite_at", _MPI_File_iwrite_at},
  { "File_seek", _MPI_File_seek},
  { "Win_wait", _MPI_Win_wait},
  { "File_read_all_end", _MPI_File_read_all_end},
  { "File_get_atomicity", _MPI_File_get_atomicity},
  { "File_read_at_all", _MPI_File_read_at_all},
  { "File_read_ordered", _MPI_File_read_ordered},
  { "Allreduce", _MPI_Allreduce},
  { "Ibsend", _MPI_Ibsend},
  { "Initialized", _MPI_Initialized},
  { "Win_start", _MPI_Win_start},
  { "Grequest_start", _MPI_Grequest_start},
  { "Type_create_struct", _MPI_Type_create_struct},
  { "Comm_set_attr", _MPI_Comm_set_attr},
  { "Comm_delete_attr", _MPI_Comm_delete_attr},
  { "File_get_position", _MPI_File_get_position},
  { "Group_intersection", _MPI_Group_intersection},
  { "File_set_size", _MPI_File_set_size},
  { "Ssend", _MPI_Ssend},
  { "File_get_byte_offset", _MPI_File_get_byte_offset},
  { "File_read_ordered_begin", _MPI_File_read_ordered_begin},
  { "Op_free", _MPI_Op_free},
  { "File_read", _MPI_File_read},
  { "Send", _MPI_Send},
  { "Type_get_true_extent", _MPI_Type_get_true_extent},
  { "File_iread_at", _MPI_File_iread_at},
  { "File_get_info", _MPI_File_get_info},
  { "Issend", _MPI_Issend},
  { "Finalized", _MPI_Finalized},
  { "Alltoall", _MPI_Alltoall},
  { "Publish_name", _MPI_Publish_name},
  { "File_get_position_shared", _MPI_File_get_position_shared},
  { "Type_create_keyval", _MPI_Type_create_keyval},
  { "Info_set", _MPI_Info_set},
  { "File_open", _MPI_File_open},
  { "Wait", _MPI_Wait},
  { "Comm_create_keyval", _MPI_Comm_create_keyval},
  { "File_write_at_all_end", _MPI_File_write_at_all_end},
  { "Win_delete_attr", _MPI_Win_delete_attr},
  { "Request_free", _MPI_Request_free},
  { "Gatherv", _MPI_Gatherv},
  { "Sendrecv_replace", _MPI_Sendrecv_replace},
  { "Group_incl", _MPI_Group_incl},
  { "Comm_disconnect", _MPI_Comm_disconnect},
  { "Reduce_scatter", _MPI_Reduce_scatter},
  { "File_get_view", _MPI_File_get_view},
  { "Dims_create", _MPI_Dims_create},
  { "Recv_init", _MPI_Recv_init},
  { "Alltoallw", _MPI_Alltoallw},
  { "Comm_compare", _MPI_Comm_compare},
  { "Exscan", _MPI_Exscan},
  { "Type_vector", _MPI_Type_vector},
  { "Get_elements", _MPI_Get_elements},
  { "Pack_external", _MPI_Pack_external},
  { "File_iwrite_shared", _MPI_File_iwrite_shared},
  { "Win_get_name", _MPI_Win_get_name},
  { "Info_free", _MPI_Info_free},
  { "Comm_get_parent", _MPI_Comm_get_parent},
  { "Group_excl", _MPI_Group_excl},
  { "Finalize", _MPI_Finalize},
  { "Lookup_name", _MPI_Lookup_name},
  { "Free_mem", _MPI_Free_mem},
  { "Win_free_keyval", _MPI_Win_free_keyval},
  { "Comm_remote_size", _MPI_Comm_remote_size},
  { "Type_create_hvector", _MPI_Type_create_hvector},
  { "Cart_rank", _MPI_Cart_rank},
  { "Unpack", _MPI_Unpack},
  { "Status_set_cancelled", _MPI_Status_set_cancelled},
  { "Cartdim_get", _MPI_Cartdim_get},
  { "Win_set_errhandler", _MPI_Win_set_errhandler},
  { "File_sync", _MPI_File_sync},
  { "Type_size", _MPI_Type_size},
  { "Allgather", _MPI_Allgather},
  { "Comm_rank", _MPI_Comm_rank},
  { "Register_datarep", _MPI_Register_datarep},
  { "Buffer_attach", _MPI_Buffer_attach},
  { "Win_free", _MPI_Win_free},
  { "Type_set_attr", _MPI_Type_set_attr},
  { "File_write_all_begin", _MPI_File_write_all_begin},
  { "Info_get_nkeys", _MPI_Info_get_nkeys},
  { "Type_indexed", _MPI_Type_indexed},
  { "Sendrecv", _MPI_Sendrecv},
  { "Group_union", _MPI_Group_union},
  { "File_iread", _MPI_File_iread},
  { "Group_size", _MPI_Group_size},
  { "Wtime", _MPI_Wtime},
  { "File_delete", _MPI_File_delete},
  { "Testall", _MPI_Testall},
  { "Type_match_size", _MPI_Type_match_size},
  { "File_read_shared", _MPI_File_read_shared},
  { "Add_error_code", _MPI_Add_error_code},
  { "Get_version", _MPI_Get_version},
  { "Testsome", _MPI_Testsome},
  { "Reduce", _MPI_Reduce},
  { "Type_dup", _MPI_Type_dup},
  { "Topo_test", _MPI_Topo_test},
  { "Type_get_attr", _MPI_Type_get_attr},
  { "Type_get_envelope", _MPI_Type_get_envelope},
  { "Comm_join", _MPI_Comm_join},
  { "Cart_create", _MPI_Cart_create},
  { "File_write_ordered_begin", _MPI_File_write_ordered_begin},
  { "Get_count", _MPI_Get_count},
  { "Irsend", _MPI_Irsend},
  { "Add_error_string", _MPI_Add_error_string},
  { "Barrier", _MPI_Barrier},
  { "File_set_view", _MPI_File_set_view},
  { "Iprobe", _MPI_Iprobe},
  { "Unpublish_name", _MPI_Unpublish_name},
  { "Error_class", _MPI_Error_class},
  { "Rsend_init", _MPI_Rsend_init},
  { "Type_contiguous", _MPI_Type_contiguous},
  { "File_get_group", _MPI_File_get_group},
  { "Waitall", _MPI_Waitall},
  { "Add_error_class", _MPI_Add_error_class},
  { "Win_call_errhandler", _MPI_Win_call_errhandler},
  { "Comm_connect", _MPI_Comm_connect},
  { "Errhandler_free", _MPI_Errhandler_free},
  { "Close_port", _MPI_Close_port},
  { "Comm_test_inter", _MPI_Comm_test_inter},
  { "File_write", _MPI_File_write},
  { "Win_lock", _MPI_Win_lock},
  { "Buffer_detach", _MPI_Buffer_detach},
  { "Op_create", _MPI_Op_create},
  { "Group_rank", _MPI_Group_rank},
  { "Graph_create", _MPI_Graph_create},
  { "Type_get_contents", _MPI_Type_get_contents},
  { "File_read_at", _MPI_File_read_at},
  { "Comm_free", _MPI_Comm_free},
  { "Allgatherv", _MPI_Allgatherv},
  { "Waitsome", _MPI_Waitsome},
  { "Graphdims_get", _MPI_Graphdims_get},
  { "Type_free_keyval", _MPI_Type_free_keyval},
  { "Send_init", _MPI_Send_init},
  { "File_close", _MPI_File_close},
  { "File_write_ordered", _MPI_File_write_ordered},
  { "Rsend", _MPI_Rsend},
  { "File_write_shared", _MPI_File_write_shared},
  { "Wtick", _MPI_Wtick},
  { "File_get_type_extent", _MPI_File_get_type_extent},
  { "Win_set_attr", _MPI_Win_set_attr},
  { "Info_dup", _MPI_Info_dup},
  { "Is_thread_main", _MPI_Is_thread_main},
  { "Win_fence", _MPI_Win_fence},
  { "File_read_all", _MPI_File_read_all},
  { "Win_unlock", _MPI_Win_unlock},
  { "Cart_sub", _MPI_Cart_sub},
  { "File_write_all", _MPI_File_write_all},
  { "Comm_group", _MPI_Comm_group},
  { "File_write_at_all_begin", _MPI_File_write_at_all_begin},
  { "Group_compare", _MPI_Group_compare},
  { "Type_get_extent", _MPI_Type_get_extent},
  { "File_get_amode", _MPI_File_get_amode},
  { "Type_create_subarray", _MPI_Type_create_subarray},
  { "File_call_errhandler", _MPI_File_call_errhandler},
  { "Intercomm_create", _MPI_Intercomm_create},
  { "Type_create_hindexed", _MPI_Type_create_hindexed},
  { "Graph_map", _MPI_Graph_map},
  { "Testany", _MPI_Testany},
  { "Win_test", _MPI_Win_test},
  { "Cart_coords", _MPI_Cart_coords},
  { "File_preallocate", _MPI_File_preallocate},
  { "Get_processor_name", _MPI_Get_processor_name},
  { "Isend", _MPI_Isend},
  { "Graph_neighbors_count", _MPI_Graph_neighbors_count},
  { "Comm_get_attr", _MPI_Comm_get_attr},
  { "Open_port", _MPI_Open_port},
  { "Get", _MPI_Get},
  { "Bsend", _MPI_Bsend},
  { "File_get_size", _MPI_File_get_size},
  { "Graph_neighbors", _MPI_Graph_neighbors},
  { "Type_commit", _MPI_Type_commit},
  { "Irecv", _MPI_Irecv},
  { "Grequest_complete", _MPI_Grequest_complete},
  { "Type_delete_attr", _MPI_Type_delete_attr},
  { "Win_post", _MPI_Win_post},
  { "Win_get_attr", _MPI_Win_get_attr},
  { "Get_address", _MPI_Get_address},
  { "Comm_accept", _MPI_Comm_accept},
  { "Bsend_init", _MPI_Bsend_init},
  { "Comm_free_keyval", _MPI_Comm_free_keyval},
  { "Put", _MPI_Put},
  { "Accumulate", _MPI_Accumulate},
  { "Info_get_nthkey", _MPI_Info_get_nthkey},
  { "Comm_create", _MPI_Comm_create},
  { "Comm_set_errhandler", _MPI_Comm_set_errhandler},
  { "File_write_at_all", _MPI_File_write_at_all},
  { "Type_create_resized", _MPI_Type_create_resized},
  { "Cancel", _MPI_Cancel},
  { "Abort", _MPI_Abort},
  { "File_set_atomicity", _MPI_File_set_atomicity},
  { "Comm_get_name", _MPI_Comm_get_name},
  { "File_write_at", _MPI_File_write_at},
  { "Startall", _MPI_Startall},
  { "Comm_split", _MPI_Comm_split},
  { "Type_create_darray", _MPI_Type_create_darray},
  { "Start", _MPI_Start},
  { "Group_difference", _MPI_Group_difference},
  { "Type_free", _MPI_Type_free},
  { "Info_get_valuelen", _MPI_Info_get_valuelen},
  { "File_write_ordered_end", _MPI_File_write_ordered_end},
  { "File_get_errhandler", _MPI_File_get_errhandler},
  { "Win_create", _MPI_Win_create},
  { "Type_set_name", _MPI_Type_set_name},
  { "Comm_get_errhandler", _MPI_Comm_get_errhandler},
  { "Waitany", _MPI_Waitany},
  { "Win_complete", _MPI_Win_complete},
  { "File_read_ordered_end", _MPI_File_read_ordered_end},
  { "Bcast", _MPI_Bcast},
  { "File_write_all_end", _MPI_File_write_all_end},
  { "Ssend_init", _MPI_Ssend_init},
  { "Request_get_status", _MPI_Request_get_status},
  { "File_iwrite", _MPI_File_iwrite},
  { "File_set_errhandler", _MPI_File_set_errhandler},
  { "Comm_dup", _MPI_Comm_dup},
  { "Init", _MPI_Init},
  {NULL, NULL}};
