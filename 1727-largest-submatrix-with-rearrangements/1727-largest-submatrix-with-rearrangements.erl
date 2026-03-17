-spec largest_submatrix(Matrix :: [[integer()]]) -> integer().
largest_submatrix(Matrix) ->
    Heights = build_heights(Matrix, []),
    max_area(Heights, 0).

build_heights([], _) -> [];
build_heights([Row | Rest], Prev) ->
    H = build_row(Row, Prev),
    [H | build_heights(Rest, H)].

build_row(Row, []) ->
    Row;
build_row(Row, Prev) ->
    lists:zipwith(
        fun(X, P) ->
            case X of
                1 -> P + 1;
                _ -> 0
            end
        end, Row, Prev).

max_area([], Max) -> Max;
max_area([Row | Rest], Max) ->
    Sorted = lists:reverse(lists:sort(Row)),
    Area = row_area(Sorted, 1, 0),
    max_area(Rest, max(Max, Area)).

row_area([], _, Best) -> Best;
row_area([H | T], W, Best) ->
    Area = H * W,
    row_area(T, W + 1, max(Best, Area)).