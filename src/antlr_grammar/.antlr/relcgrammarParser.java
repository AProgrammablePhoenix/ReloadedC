// Generated from /home/alexandre/LanguagesProjects/ReloadedC/src/antlr_grammar/relcgrammar.g4 by ANTLR 4.9.2
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class relcgrammarParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.9.2", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		INT_LITERAL=1, FLOAT_LITERAL=2, TYPE=3, NativeProtoDecl=4, ID=5, CHAR=6, 
		PLUS=7, MINUS=8, MULT=9, DIV=10, EQUAL=11, SEMI=12, COMMA=13, LPAREN=14, 
		RPAREN=15, LCURL=16, RCURL=17, NATIVE_SCOPE=18, WS=19;
	public static final int
		RULE_program = 0, RULE_global_statement = 1, RULE_statement = 2, RULE_assignment = 3, 
		RULE_initialization = 4, RULE_exp = 5, RULE_native_call = 6, RULE_arguments_list = 7, 
		RULE_parameter = 8, RULE_parameters_list = 9, RULE_native_func_prototype = 10, 
		RULE_func_prototype = 11, RULE_func_declaration = 12, RULE_scope = 13, 
		RULE_bordered_scope = 14, RULE_func_scope = 15, RULE_func_body = 16;
	private static String[] makeRuleNames() {
		return new String[] {
			"program", "global_statement", "statement", "assignment", "initialization", 
			"exp", "native_call", "arguments_list", "parameter", "parameters_list", 
			"native_func_prototype", "func_prototype", "func_declaration", "scope", 
			"bordered_scope", "func_scope", "func_body"
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

	@Override
	public String getGrammarFileName() { return "relcgrammar.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public relcgrammarParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	public static class ProgramContext extends ParserRuleContext {
		public List<Global_statementContext> global_statement() {
			return getRuleContexts(Global_statementContext.class);
		}
		public Global_statementContext global_statement(int i) {
			return getRuleContext(Global_statementContext.class,i);
		}
		public ProgramContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_program; }
	}

	public final ProgramContext program() throws RecognitionException {
		ProgramContext _localctx = new ProgramContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_program);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(35); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				{
				setState(34);
				global_statement();
				}
				}
				setState(37); 
				_errHandler.sync(this);
				_la = _input.LA(1);
			} while ( _la==TYPE || _la==NativeProtoDecl );
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Global_statementContext extends ParserRuleContext {
		public Native_func_prototypeContext native_func_prototype() {
			return getRuleContext(Native_func_prototypeContext.class,0);
		}
		public Func_prototypeContext func_prototype() {
			return getRuleContext(Func_prototypeContext.class,0);
		}
		public Func_bodyContext func_body() {
			return getRuleContext(Func_bodyContext.class,0);
		}
		public Global_statementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_global_statement; }
	}

	public final Global_statementContext global_statement() throws RecognitionException {
		Global_statementContext _localctx = new Global_statementContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_global_statement);
		try {
			setState(42);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,1,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(39);
				native_func_prototype();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(40);
				func_prototype();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(41);
				func_body();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class StatementContext extends ParserRuleContext {
		public AssignmentContext assignment() {
			return getRuleContext(AssignmentContext.class,0);
		}
		public TerminalNode SEMI() { return getToken(relcgrammarParser.SEMI, 0); }
		public InitializationContext initialization() {
			return getRuleContext(InitializationContext.class,0);
		}
		public ExpContext exp() {
			return getRuleContext(ExpContext.class,0);
		}
		public StatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_statement; }
	}

	public final StatementContext statement() throws RecognitionException {
		StatementContext _localctx = new StatementContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_statement);
		try {
			setState(56);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,2,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(44);
				assignment();
				setState(45);
				match(SEMI);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(47);
				initialization();
				setState(48);
				match(SEMI);
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(50);
				exp(0);
				setState(51);
				match(SEMI);
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(53);
				assignment();
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(54);
				initialization();
				}
				break;
			case 6:
				enterOuterAlt(_localctx, 6);
				{
				setState(55);
				exp(0);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class AssignmentContext extends ParserRuleContext {
		public TerminalNode ID() { return getToken(relcgrammarParser.ID, 0); }
		public TerminalNode EQUAL() { return getToken(relcgrammarParser.EQUAL, 0); }
		public ExpContext exp() {
			return getRuleContext(ExpContext.class,0);
		}
		public AssignmentContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_assignment; }
	}

	public final AssignmentContext assignment() throws RecognitionException {
		AssignmentContext _localctx = new AssignmentContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_assignment);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(58);
			match(ID);
			setState(59);
			match(EQUAL);
			setState(60);
			exp(0);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class InitializationContext extends ParserRuleContext {
		public TerminalNode TYPE() { return getToken(relcgrammarParser.TYPE, 0); }
		public TerminalNode ID() { return getToken(relcgrammarParser.ID, 0); }
		public TerminalNode EQUAL() { return getToken(relcgrammarParser.EQUAL, 0); }
		public ExpContext exp() {
			return getRuleContext(ExpContext.class,0);
		}
		public InitializationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_initialization; }
	}

	public final InitializationContext initialization() throws RecognitionException {
		InitializationContext _localctx = new InitializationContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_initialization);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(62);
			match(TYPE);
			setState(63);
			match(ID);
			setState(64);
			match(EQUAL);
			setState(65);
			exp(0);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ExpContext extends ParserRuleContext {
		public Native_callContext native_call() {
			return getRuleContext(Native_callContext.class,0);
		}
		public TerminalNode ID() { return getToken(relcgrammarParser.ID, 0); }
		public TerminalNode LPAREN() { return getToken(relcgrammarParser.LPAREN, 0); }
		public Arguments_listContext arguments_list() {
			return getRuleContext(Arguments_listContext.class,0);
		}
		public TerminalNode RPAREN() { return getToken(relcgrammarParser.RPAREN, 0); }
		public TerminalNode INT_LITERAL() { return getToken(relcgrammarParser.INT_LITERAL, 0); }
		public TerminalNode FLOAT_LITERAL() { return getToken(relcgrammarParser.FLOAT_LITERAL, 0); }
		public TerminalNode CHAR() { return getToken(relcgrammarParser.CHAR, 0); }
		public List<ExpContext> exp() {
			return getRuleContexts(ExpContext.class);
		}
		public ExpContext exp(int i) {
			return getRuleContext(ExpContext.class,i);
		}
		public TerminalNode PLUS() { return getToken(relcgrammarParser.PLUS, 0); }
		public TerminalNode MINUS() { return getToken(relcgrammarParser.MINUS, 0); }
		public TerminalNode MULT() { return getToken(relcgrammarParser.MULT, 0); }
		public TerminalNode DIV() { return getToken(relcgrammarParser.DIV, 0); }
		public ExpContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_exp; }
	}

	public final ExpContext exp() throws RecognitionException {
		return exp(0);
	}

	private ExpContext exp(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ExpContext _localctx = new ExpContext(_ctx, _parentState);
		ExpContext _prevctx = _localctx;
		int _startState = 10;
		enterRecursionRule(_localctx, 10, RULE_exp, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(85);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,3,_ctx) ) {
			case 1:
				{
				setState(68);
				native_call();
				}
				break;
			case 2:
				{
				setState(69);
				match(ID);
				setState(70);
				match(LPAREN);
				setState(71);
				arguments_list();
				setState(72);
				match(RPAREN);
				}
				break;
			case 3:
				{
				setState(74);
				match(ID);
				setState(75);
				match(LPAREN);
				setState(76);
				match(RPAREN);
				}
				break;
			case 4:
				{
				setState(77);
				match(ID);
				}
				break;
			case 5:
				{
				setState(78);
				match(INT_LITERAL);
				}
				break;
			case 6:
				{
				setState(79);
				match(FLOAT_LITERAL);
				}
				break;
			case 7:
				{
				setState(80);
				match(CHAR);
				}
				break;
			case 8:
				{
				setState(81);
				match(LPAREN);
				setState(82);
				exp(0);
				setState(83);
				match(RPAREN);
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(101);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,5,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(99);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,4,_ctx) ) {
					case 1:
						{
						_localctx = new ExpContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_exp);
						setState(87);
						if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
						setState(88);
						match(PLUS);
						setState(89);
						exp(6);
						}
						break;
					case 2:
						{
						_localctx = new ExpContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_exp);
						setState(90);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(91);
						match(MINUS);
						setState(92);
						exp(5);
						}
						break;
					case 3:
						{
						_localctx = new ExpContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_exp);
						setState(93);
						if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
						setState(94);
						match(MULT);
						setState(95);
						exp(4);
						}
						break;
					case 4:
						{
						_localctx = new ExpContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_exp);
						setState(96);
						if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
						setState(97);
						match(DIV);
						setState(98);
						exp(3);
						}
						break;
					}
					} 
				}
				setState(103);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,5,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class Native_callContext extends ParserRuleContext {
		public TerminalNode NATIVE_SCOPE() { return getToken(relcgrammarParser.NATIVE_SCOPE, 0); }
		public TerminalNode ID() { return getToken(relcgrammarParser.ID, 0); }
		public TerminalNode LPAREN() { return getToken(relcgrammarParser.LPAREN, 0); }
		public TerminalNode RPAREN() { return getToken(relcgrammarParser.RPAREN, 0); }
		public Arguments_listContext arguments_list() {
			return getRuleContext(Arguments_listContext.class,0);
		}
		public Native_callContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_native_call; }
	}

	public final Native_callContext native_call() throws RecognitionException {
		Native_callContext _localctx = new Native_callContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_native_call);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(104);
			match(NATIVE_SCOPE);
			setState(105);
			match(ID);
			setState(106);
			match(LPAREN);
			setState(108);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << INT_LITERAL) | (1L << FLOAT_LITERAL) | (1L << ID) | (1L << CHAR) | (1L << LPAREN) | (1L << NATIVE_SCOPE))) != 0)) {
				{
				setState(107);
				arguments_list();
				}
			}

			setState(110);
			match(RPAREN);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Arguments_listContext extends ParserRuleContext {
		public List<ExpContext> exp() {
			return getRuleContexts(ExpContext.class);
		}
		public ExpContext exp(int i) {
			return getRuleContext(ExpContext.class,i);
		}
		public List<TerminalNode> COMMA() { return getTokens(relcgrammarParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(relcgrammarParser.COMMA, i);
		}
		public Arguments_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_arguments_list; }
	}

	public final Arguments_listContext arguments_list() throws RecognitionException {
		Arguments_listContext _localctx = new Arguments_listContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_arguments_list);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(112);
			exp(0);
			setState(117);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==COMMA) {
				{
				{
				setState(113);
				match(COMMA);
				setState(114);
				exp(0);
				}
				}
				setState(119);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ParameterContext extends ParserRuleContext {
		public TerminalNode TYPE() { return getToken(relcgrammarParser.TYPE, 0); }
		public TerminalNode ID() { return getToken(relcgrammarParser.ID, 0); }
		public ParameterContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_parameter; }
	}

	public final ParameterContext parameter() throws RecognitionException {
		ParameterContext _localctx = new ParameterContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_parameter);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(120);
			match(TYPE);
			setState(121);
			match(ID);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Parameters_listContext extends ParserRuleContext {
		public List<ParameterContext> parameter() {
			return getRuleContexts(ParameterContext.class);
		}
		public ParameterContext parameter(int i) {
			return getRuleContext(ParameterContext.class,i);
		}
		public List<TerminalNode> COMMA() { return getTokens(relcgrammarParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(relcgrammarParser.COMMA, i);
		}
		public Parameters_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_parameters_list; }
	}

	public final Parameters_listContext parameters_list() throws RecognitionException {
		Parameters_listContext _localctx = new Parameters_listContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_parameters_list);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(123);
			parameter();
			setState(128);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==COMMA) {
				{
				{
				setState(124);
				match(COMMA);
				setState(125);
				parameter();
				}
				}
				setState(130);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Native_func_prototypeContext extends ParserRuleContext {
		public TerminalNode NativeProtoDecl() { return getToken(relcgrammarParser.NativeProtoDecl, 0); }
		public TerminalNode LPAREN() { return getToken(relcgrammarParser.LPAREN, 0); }
		public TerminalNode ID() { return getToken(relcgrammarParser.ID, 0); }
		public TerminalNode RPAREN() { return getToken(relcgrammarParser.RPAREN, 0); }
		public Func_prototypeContext func_prototype() {
			return getRuleContext(Func_prototypeContext.class,0);
		}
		public Native_func_prototypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_native_func_prototype; }
	}

	public final Native_func_prototypeContext native_func_prototype() throws RecognitionException {
		Native_func_prototypeContext _localctx = new Native_func_prototypeContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_native_func_prototype);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(131);
			match(NativeProtoDecl);
			setState(132);
			match(LPAREN);
			setState(133);
			match(ID);
			setState(134);
			match(RPAREN);
			setState(135);
			func_prototype();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Func_prototypeContext extends ParserRuleContext {
		public Func_declarationContext func_declaration() {
			return getRuleContext(Func_declarationContext.class,0);
		}
		public TerminalNode SEMI() { return getToken(relcgrammarParser.SEMI, 0); }
		public Func_prototypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_func_prototype; }
	}

	public final Func_prototypeContext func_prototype() throws RecognitionException {
		Func_prototypeContext _localctx = new Func_prototypeContext(_ctx, getState());
		enterRule(_localctx, 22, RULE_func_prototype);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(137);
			func_declaration();
			setState(138);
			match(SEMI);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Func_declarationContext extends ParserRuleContext {
		public TerminalNode TYPE() { return getToken(relcgrammarParser.TYPE, 0); }
		public TerminalNode ID() { return getToken(relcgrammarParser.ID, 0); }
		public TerminalNode LPAREN() { return getToken(relcgrammarParser.LPAREN, 0); }
		public Parameters_listContext parameters_list() {
			return getRuleContext(Parameters_listContext.class,0);
		}
		public TerminalNode RPAREN() { return getToken(relcgrammarParser.RPAREN, 0); }
		public Func_declarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_func_declaration; }
	}

	public final Func_declarationContext func_declaration() throws RecognitionException {
		Func_declarationContext _localctx = new Func_declarationContext(_ctx, getState());
		enterRule(_localctx, 24, RULE_func_declaration);
		try {
			setState(150);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,9,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(140);
				match(TYPE);
				setState(141);
				match(ID);
				setState(142);
				match(LPAREN);
				setState(143);
				parameters_list();
				setState(144);
				match(RPAREN);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(146);
				match(TYPE);
				setState(147);
				match(ID);
				setState(148);
				match(LPAREN);
				setState(149);
				match(RPAREN);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ScopeContext extends ParserRuleContext {
		public List<StatementContext> statement() {
			return getRuleContexts(StatementContext.class);
		}
		public StatementContext statement(int i) {
			return getRuleContext(StatementContext.class,i);
		}
		public ScopeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_scope; }
	}

	public final ScopeContext scope() throws RecognitionException {
		ScopeContext _localctx = new ScopeContext(_ctx, getState());
		enterRule(_localctx, 26, RULE_scope);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(153); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				{
				setState(152);
				statement();
				}
				}
				setState(155); 
				_errHandler.sync(this);
				_la = _input.LA(1);
			} while ( (((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << INT_LITERAL) | (1L << FLOAT_LITERAL) | (1L << TYPE) | (1L << ID) | (1L << CHAR) | (1L << LPAREN) | (1L << NATIVE_SCOPE))) != 0) );
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Bordered_scopeContext extends ParserRuleContext {
		public TerminalNode LCURL() { return getToken(relcgrammarParser.LCURL, 0); }
		public ScopeContext scope() {
			return getRuleContext(ScopeContext.class,0);
		}
		public TerminalNode RCURL() { return getToken(relcgrammarParser.RCURL, 0); }
		public Bordered_scopeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_bordered_scope; }
	}

	public final Bordered_scopeContext bordered_scope() throws RecognitionException {
		Bordered_scopeContext _localctx = new Bordered_scopeContext(_ctx, getState());
		enterRule(_localctx, 28, RULE_bordered_scope);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(157);
			match(LCURL);
			setState(158);
			scope();
			setState(159);
			match(RCURL);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Func_scopeContext extends ParserRuleContext {
		public Bordered_scopeContext bordered_scope() {
			return getRuleContext(Bordered_scopeContext.class,0);
		}
		public TerminalNode LCURL() { return getToken(relcgrammarParser.LCURL, 0); }
		public TerminalNode RCURL() { return getToken(relcgrammarParser.RCURL, 0); }
		public Func_scopeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_func_scope; }
	}

	public final Func_scopeContext func_scope() throws RecognitionException {
		Func_scopeContext _localctx = new Func_scopeContext(_ctx, getState());
		enterRule(_localctx, 30, RULE_func_scope);
		try {
			setState(164);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,11,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(161);
				bordered_scope();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(162);
				match(LCURL);
				setState(163);
				match(RCURL);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Func_bodyContext extends ParserRuleContext {
		public Func_declarationContext func_declaration() {
			return getRuleContext(Func_declarationContext.class,0);
		}
		public Func_scopeContext func_scope() {
			return getRuleContext(Func_scopeContext.class,0);
		}
		public Func_bodyContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_func_body; }
	}

	public final Func_bodyContext func_body() throws RecognitionException {
		Func_bodyContext _localctx = new Func_bodyContext(_ctx, getState());
		enterRule(_localctx, 32, RULE_func_body);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(166);
			func_declaration();
			setState(167);
			func_scope();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 5:
			return exp_sempred((ExpContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean exp_sempred(ExpContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 5);
		case 1:
			return precpred(_ctx, 4);
		case 2:
			return precpred(_ctx, 3);
		case 3:
			return precpred(_ctx, 2);
		}
		return true;
	}

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3\25\u00ac\4\2\t\2"+
		"\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13"+
		"\t\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22\t\22"+
		"\3\2\6\2&\n\2\r\2\16\2\'\3\3\3\3\3\3\5\3-\n\3\3\4\3\4\3\4\3\4\3\4\3\4"+
		"\3\4\3\4\3\4\3\4\3\4\3\4\5\4;\n\4\3\5\3\5\3\5\3\5\3\6\3\6\3\6\3\6\3\6"+
		"\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3"+
		"\7\5\7X\n\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\7\7f\n\7\f"+
		"\7\16\7i\13\7\3\b\3\b\3\b\3\b\5\bo\n\b\3\b\3\b\3\t\3\t\3\t\7\tv\n\t\f"+
		"\t\16\ty\13\t\3\n\3\n\3\n\3\13\3\13\3\13\7\13\u0081\n\13\f\13\16\13\u0084"+
		"\13\13\3\f\3\f\3\f\3\f\3\f\3\f\3\r\3\r\3\r\3\16\3\16\3\16\3\16\3\16\3"+
		"\16\3\16\3\16\3\16\3\16\5\16\u0099\n\16\3\17\6\17\u009c\n\17\r\17\16\17"+
		"\u009d\3\20\3\20\3\20\3\20\3\21\3\21\3\21\5\21\u00a7\n\21\3\22\3\22\3"+
		"\22\3\22\2\3\f\23\2\4\6\b\n\f\16\20\22\24\26\30\32\34\36 \"\2\2\2\u00b3"+
		"\2%\3\2\2\2\4,\3\2\2\2\6:\3\2\2\2\b<\3\2\2\2\n@\3\2\2\2\fW\3\2\2\2\16"+
		"j\3\2\2\2\20r\3\2\2\2\22z\3\2\2\2\24}\3\2\2\2\26\u0085\3\2\2\2\30\u008b"+
		"\3\2\2\2\32\u0098\3\2\2\2\34\u009b\3\2\2\2\36\u009f\3\2\2\2 \u00a6\3\2"+
		"\2\2\"\u00a8\3\2\2\2$&\5\4\3\2%$\3\2\2\2&\'\3\2\2\2\'%\3\2\2\2\'(\3\2"+
		"\2\2(\3\3\2\2\2)-\5\26\f\2*-\5\30\r\2+-\5\"\22\2,)\3\2\2\2,*\3\2\2\2,"+
		"+\3\2\2\2-\5\3\2\2\2./\5\b\5\2/\60\7\16\2\2\60;\3\2\2\2\61\62\5\n\6\2"+
		"\62\63\7\16\2\2\63;\3\2\2\2\64\65\5\f\7\2\65\66\7\16\2\2\66;\3\2\2\2\67"+
		";\5\b\5\28;\5\n\6\29;\5\f\7\2:.\3\2\2\2:\61\3\2\2\2:\64\3\2\2\2:\67\3"+
		"\2\2\2:8\3\2\2\2:9\3\2\2\2;\7\3\2\2\2<=\7\7\2\2=>\7\r\2\2>?\5\f\7\2?\t"+
		"\3\2\2\2@A\7\5\2\2AB\7\7\2\2BC\7\r\2\2CD\5\f\7\2D\13\3\2\2\2EF\b\7\1\2"+
		"FX\5\16\b\2GH\7\7\2\2HI\7\20\2\2IJ\5\20\t\2JK\7\21\2\2KX\3\2\2\2LM\7\7"+
		"\2\2MN\7\20\2\2NX\7\21\2\2OX\7\7\2\2PX\7\3\2\2QX\7\4\2\2RX\7\b\2\2ST\7"+
		"\20\2\2TU\5\f\7\2UV\7\21\2\2VX\3\2\2\2WE\3\2\2\2WG\3\2\2\2WL\3\2\2\2W"+
		"O\3\2\2\2WP\3\2\2\2WQ\3\2\2\2WR\3\2\2\2WS\3\2\2\2Xg\3\2\2\2YZ\f\7\2\2"+
		"Z[\7\t\2\2[f\5\f\7\b\\]\f\6\2\2]^\7\n\2\2^f\5\f\7\7_`\f\5\2\2`a\7\13\2"+
		"\2af\5\f\7\6bc\f\4\2\2cd\7\f\2\2df\5\f\7\5eY\3\2\2\2e\\\3\2\2\2e_\3\2"+
		"\2\2eb\3\2\2\2fi\3\2\2\2ge\3\2\2\2gh\3\2\2\2h\r\3\2\2\2ig\3\2\2\2jk\7"+
		"\24\2\2kl\7\7\2\2ln\7\20\2\2mo\5\20\t\2nm\3\2\2\2no\3\2\2\2op\3\2\2\2"+
		"pq\7\21\2\2q\17\3\2\2\2rw\5\f\7\2st\7\17\2\2tv\5\f\7\2us\3\2\2\2vy\3\2"+
		"\2\2wu\3\2\2\2wx\3\2\2\2x\21\3\2\2\2yw\3\2\2\2z{\7\5\2\2{|\7\7\2\2|\23"+
		"\3\2\2\2}\u0082\5\22\n\2~\177\7\17\2\2\177\u0081\5\22\n\2\u0080~\3\2\2"+
		"\2\u0081\u0084\3\2\2\2\u0082\u0080\3\2\2\2\u0082\u0083\3\2\2\2\u0083\25"+
		"\3\2\2\2\u0084\u0082\3\2\2\2\u0085\u0086\7\6\2\2\u0086\u0087\7\20\2\2"+
		"\u0087\u0088\7\7\2\2\u0088\u0089\7\21\2\2\u0089\u008a\5\30\r\2\u008a\27"+
		"\3\2\2\2\u008b\u008c\5\32\16\2\u008c\u008d\7\16\2\2\u008d\31\3\2\2\2\u008e"+
		"\u008f\7\5\2\2\u008f\u0090\7\7\2\2\u0090\u0091\7\20\2\2\u0091\u0092\5"+
		"\24\13\2\u0092\u0093\7\21\2\2\u0093\u0099\3\2\2\2\u0094\u0095\7\5\2\2"+
		"\u0095\u0096\7\7\2\2\u0096\u0097\7\20\2\2\u0097\u0099\7\21\2\2\u0098\u008e"+
		"\3\2\2\2\u0098\u0094\3\2\2\2\u0099\33\3\2\2\2\u009a\u009c\5\6\4\2\u009b"+
		"\u009a\3\2\2\2\u009c\u009d\3\2\2\2\u009d\u009b\3\2\2\2\u009d\u009e\3\2"+
		"\2\2\u009e\35\3\2\2\2\u009f\u00a0\7\22\2\2\u00a0\u00a1\5\34\17\2\u00a1"+
		"\u00a2\7\23\2\2\u00a2\37\3\2\2\2\u00a3\u00a7\5\36\20\2\u00a4\u00a5\7\22"+
		"\2\2\u00a5\u00a7\7\23\2\2\u00a6\u00a3\3\2\2\2\u00a6\u00a4\3\2\2\2\u00a7"+
		"!\3\2\2\2\u00a8\u00a9\5\32\16\2\u00a9\u00aa\5 \21\2\u00aa#\3\2\2\2\16"+
		"\',:Wegnw\u0082\u0098\u009d\u00a6";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}