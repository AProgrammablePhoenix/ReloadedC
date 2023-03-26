// Generated from /home/alexandre/LanguagesProjects/ReloadedC/src/antlr_grammar/relcgrammar.g4 by ANTLR 4.9.2
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class relcgrammarLexer extends Lexer {
	static { RuntimeMetaData.checkVersion("4.9.2", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		INT_LITERAL=1, FLOAT_LITERAL=2, TYPE=3, NativeProtoDecl=4, ID=5, CHAR=6, 
		PLUS=7, MINUS=8, MULT=9, DIV=10, EQUAL=11, SEMI=12, COMMA=13, LPAREN=14, 
		RPAREN=15, LCURL=16, RCURL=17, NATIVE_SCOPE=18, WS=19;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"INT_LITERAL", "FLOAT_LITERAL", "TYPE", "NativeProtoDecl", "ID", "CHAR", 
			"PLUS", "MINUS", "MULT", "DIV", "EQUAL", "SEMI", "COMMA", "LPAREN", "RPAREN", 
			"LCURL", "RCURL", "NATIVE_SCOPE", "WS"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, null, null, null, "'__nativedecl'", null, null, "'+'", "'-'", "'*'", 
			"'/'", "'='", "';'", "','", "'('", "')'", "'{'", "'}'", "'::'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "INT_LITERAL", "FLOAT_LITERAL", "TYPE", "NativeProtoDecl", "ID", 
			"CHAR", "PLUS", "MINUS", "MULT", "DIV", "EQUAL", "SEMI", "COMMA", "LPAREN", 
			"RPAREN", "LCURL", "RCURL", "NATIVE_SCOPE", "WS"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}


	public relcgrammarLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "relcgrammar.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getChannelNames() { return channelNames; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\2\25\u0082\b\1\4\2"+
		"\t\2\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4"+
		"\13\t\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22"+
		"\t\22\4\23\t\23\4\24\t\24\3\2\6\2+\n\2\r\2\16\2,\3\3\6\3\60\n\3\r\3\16"+
		"\3\61\3\3\3\3\6\3\66\n\3\r\3\16\3\67\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3"+
		"\4\3\4\3\4\3\4\3\4\3\4\3\4\5\4I\n\4\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3"+
		"\5\3\5\3\5\3\5\3\5\3\6\3\6\7\6Z\n\6\f\6\16\6]\13\6\3\7\3\7\3\7\3\7\3\b"+
		"\3\b\3\t\3\t\3\n\3\n\3\13\3\13\3\f\3\f\3\r\3\r\3\16\3\16\3\17\3\17\3\20"+
		"\3\20\3\21\3\21\3\22\3\22\3\23\3\23\3\23\3\24\6\24}\n\24\r\24\16\24~\3"+
		"\24\3\24\2\2\25\3\3\5\4\7\5\t\6\13\7\r\b\17\t\21\n\23\13\25\f\27\r\31"+
		"\16\33\17\35\20\37\21!\22#\23%\24\'\25\3\2\6\3\2\62;\5\2C\\aac|\6\2\62"+
		";C\\aac|\5\2\13\f\17\17\"\"\2\u0089\2\3\3\2\2\2\2\5\3\2\2\2\2\7\3\2\2"+
		"\2\2\t\3\2\2\2\2\13\3\2\2\2\2\r\3\2\2\2\2\17\3\2\2\2\2\21\3\2\2\2\2\23"+
		"\3\2\2\2\2\25\3\2\2\2\2\27\3\2\2\2\2\31\3\2\2\2\2\33\3\2\2\2\2\35\3\2"+
		"\2\2\2\37\3\2\2\2\2!\3\2\2\2\2#\3\2\2\2\2%\3\2\2\2\2\'\3\2\2\2\3*\3\2"+
		"\2\2\5/\3\2\2\2\7H\3\2\2\2\tJ\3\2\2\2\13W\3\2\2\2\r^\3\2\2\2\17b\3\2\2"+
		"\2\21d\3\2\2\2\23f\3\2\2\2\25h\3\2\2\2\27j\3\2\2\2\31l\3\2\2\2\33n\3\2"+
		"\2\2\35p\3\2\2\2\37r\3\2\2\2!t\3\2\2\2#v\3\2\2\2%x\3\2\2\2\'|\3\2\2\2"+
		")+\t\2\2\2*)\3\2\2\2+,\3\2\2\2,*\3\2\2\2,-\3\2\2\2-\4\3\2\2\2.\60\t\2"+
		"\2\2/.\3\2\2\2\60\61\3\2\2\2\61/\3\2\2\2\61\62\3\2\2\2\62\63\3\2\2\2\63"+
		"\65\13\2\2\2\64\66\t\2\2\2\65\64\3\2\2\2\66\67\3\2\2\2\67\65\3\2\2\2\67"+
		"8\3\2\2\28\6\3\2\2\29:\7x\2\2:;\7q\2\2;<\7k\2\2<I\7f\2\2=>\7e\2\2>?\7"+
		"j\2\2?@\7c\2\2@I\7t\2\2AB\7k\2\2BC\7p\2\2CI\7v\2\2DE\7n\2\2EF\7q\2\2F"+
		"G\7p\2\2GI\7i\2\2H9\3\2\2\2H=\3\2\2\2HA\3\2\2\2HD\3\2\2\2I\b\3\2\2\2J"+
		"K\7a\2\2KL\7a\2\2LM\7p\2\2MN\7c\2\2NO\7v\2\2OP\7k\2\2PQ\7x\2\2QR\7g\2"+
		"\2RS\7f\2\2ST\7g\2\2TU\7e\2\2UV\7n\2\2V\n\3\2\2\2W[\t\3\2\2XZ\t\4\2\2"+
		"YX\3\2\2\2Z]\3\2\2\2[Y\3\2\2\2[\\\3\2\2\2\\\f\3\2\2\2][\3\2\2\2^_\7)\2"+
		"\2_`\13\2\2\2`a\7)\2\2a\16\3\2\2\2bc\7-\2\2c\20\3\2\2\2de\7/\2\2e\22\3"+
		"\2\2\2fg\7,\2\2g\24\3\2\2\2hi\7\61\2\2i\26\3\2\2\2jk\7?\2\2k\30\3\2\2"+
		"\2lm\7=\2\2m\32\3\2\2\2no\7.\2\2o\34\3\2\2\2pq\7*\2\2q\36\3\2\2\2rs\7"+
		"+\2\2s \3\2\2\2tu\7}\2\2u\"\3\2\2\2vw\7\177\2\2w$\3\2\2\2xy\7<\2\2yz\7"+
		"<\2\2z&\3\2\2\2{}\t\5\2\2|{\3\2\2\2}~\3\2\2\2~|\3\2\2\2~\177\3\2\2\2\177"+
		"\u0080\3\2\2\2\u0080\u0081\b\24\2\2\u0081(\3\2\2\2\t\2,\61\67H[~\3\b\2"+
		"\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}