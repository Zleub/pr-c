open Sys;;
open String;;
open List;;
open Array;;
open Str;;
open Printf;;

class c_struct (name_init : string) (linedef_init : int) =
	object
		val linedef = linedef_init
		val name = name_init
		method get_name = name
		method get_linedef = linedef
		method print =
			print_endline("name: " ^ name);
			print_endline("linedef: " ^ string_of_int(linedef));
	end
;;

let prints x = print_endline("<" ^ x ^ ">");;

let ft_concat path file = path ^ file;;

let ft_out file message =
	let oc = open_out file in    (* create or truncate file, return channel *)
		fprintf oc "%s\n" message;   (* write something *)
		close_out oc
;;

let ft_in filename =
	let lines = ref [] in
		let chan = open_in filename in
		try
			while true; do
				lines := input_line chan :: !lines
			done; []
		with e ->
			close_in chan;
			List.rev !lines
;;

let init () =
	let check file =
		if file = "./src/" then
			let concat file = ft_concat("./src/")(file) in
			Array.iter(Sys.remove)(Array.map(concat)(Sys.readdir(file))) in
	Array.iter(check)(Sys.readdir("."))
;;

let ft_read () =
	let folder = "./inc/" in
		let inclist = Sys.readdir(folder) in
			let clist = Array.map(ft_concat(folder))(inclist) in
				Array.map(ft_in) clist
;;

let structList = ref [];;

let getstructList () =
	let static_int = ref 0 in

	let f x = List.map(String.trim)(x) in
	let readArray = Array.map(f)(ft_read()) in

	let test_struct = Str.regexp(".*struct.*") in
	let test_name = Str.regexp(".*struct.+\\(s_.+\\)") in

	let print_test s =
		static_int := !static_int + 1;
		if (string_match(test_struct)(s)(0)) then
		if (string_match(test_name)(s)(0)) then
			structList := (new c_struct(matched_group(1)(s))(!static_int) :: !structList) in

	let g x = List.iter(print_test)(x) in
		Array.iter(g)(readArray);
	structList := List.rev !structList
;;

(* let ft_write () = ;; *)

init();;
getstructList();;

let print_name ot = ot#print in
	List.iter(print_name)(!structList)
;;

(* let g x = List.map(String.trim)(x) in
	Array.map(g)(ft_read())
;;
 *)
