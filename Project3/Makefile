BIN=bin
FILES=reg_io mmf_io

all: $(FILES)
.PHONY: all clean $(FILES)

$(FILES): %: $(BIN)/%
$(BIN)/%: %.c util.h | $(BIN)
	$(CC) -o $@ $<

$(BIN)/:
	@mkdir -p $@

clean:
	@rm -f $(BIN)/*
