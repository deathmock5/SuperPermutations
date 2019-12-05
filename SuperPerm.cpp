#include <iostream>
#include <string>
#include <vector>

//https://en.wikipedia.org/wiki/Superpermutation
//https://www.gregegan.net/SCIENCE/Superpermutations/Superpermutations.html

//Seems that alot of Superpermutations are palendromes, Interesting.

namespace Super {
	const char* n2 = "121";
	const char* n3 = "123121321";
	const char* n4 = "123412314231243121342132413214321";
	const char* n5 = "\
1234512341523412534123541231452314253142351423154231245312435124315243\
1254312134521342513421534213542132451324153241352413254132145321435214\
3251432154321";
	const char* n6 = "\
1234561234516234512634512364513264513624513642513645213645123465123415\
6234152634152364152346152341652341256341253641253461253416253412653412\
3564123546123541623541263541236541326543126453162435162431562431652431\
6254316245316425314625314265314256314253614253164523146523145623145263\
1452361452316453216453126435126431526431256432156423154623154263154236\
1542316542315642135642153624153621453621543621534621354621345621346521\
3462513462153642156342165342163542163452163425163421564325164325614325\
6413256431265432165432615342613542613452613425613426513426153246513246\
5312463512463152463125463215463251463254163254613254631245632145632415\
6324516324561324563124653214653241653246153264153261453261543265143625\
1436521435621435261435216435214635214365124361524361254361245361243561\
2436514235614235164235146235142635142365143265413625413652413562413526\
41352461352416352413654213654123";
	const char* n7 = "\
1234567123456172345612734561237456123475612345761234516723451627345162\
3745162347516234571623451762345126734512637451263475126345712634517263\
4512763451236745123647512364571236451723645127364512376451234675123465\
7123465172346512734651237465123476512341567234156273415623741562347156\
2341756234157623415267341526374152634715263417526341572634152763415236\
7415236471523641752364157236415273641523764152346715234617523461572346\
1527346152374615234761523416752431765243175624317526431752463157243615\
7243165724315672431576243157264315724631527436152743165274315627431526\
7431527643152746315247631254673125463712543671254376125437162543712654\
3712564371254631725436172543167254317625431726543172564317254631275436\
1275431627543126754312765431275643127546312574361257431625743126574312\
5674312576431257463125476312457631247563124765312467531246573124653712\
4563712453671245376124537162453712645371246531724563172453617245316724\
5317624531726453172465312745631274536127453162745312674531276453127465\
3124763512467351246375124367512437651243756124375162437512643751246357\
1243657124356712435761243571624357126435712463517243651724356172435167\
2435176243517264351724635127436512743561274351627435126743512764351274\
6351247631524673152463715243671524376152437165243715624371526437152463\
1752436175243167524136725413672451362741536274135627413652741362574136\
2754136274513624751362457136245173624513762415376241357624137562413765\
2413762541376245136724153672413567241365724136752416372541637245163274\
1563274165327416352741632574163275416327451632475163245716324517632451\
6732456173245671324567312456732145763214573621457326145723614752361472\
5361472356147236514723615472361457263147526314725631472653147263514726\
3154726314572613475261347256134726513472615347261354726134572614352761\
4352671435261745326174523617452631745261374526173452617435261473526143\
7526143572614537261457321645723164752316472531647235164723156472316547\
2316457213647521364725136472153647213564721365472136457216347521634725\
1634721563472165347216354721634572164352716435217645321764523176452137\
6452173645217634521764352167453216745231674521367452163745216734521674\
3521647352164375216435721645372164573214653721465327145632714536271435\
6271436521743652147365214376251437265143725614372516437251463725143672\
5143762154372615437216543721564372154637215436721543762145376214357621\
4375621473562147536214756321475623147652314675231465723146527314562731\
4526731452763145273614527316452731465237145623714526371452367145237614\
5237164523714652317465231476253146725314627531426753142765314275631427\
5361427531642753146257314265731425673142576314257361425731642573146253\
7142653714256371425367142537614253716425371462531742653174256317425361\
7425316742531764253174625314762351467235146273514267351427635142736514\
2735614273516427351462375142637514236751423765142375614237516423751462\
3571426357142365714235671423576142357164235714623517426351742365174235\
6174235167423517642351746235147623154672315462731542673154276315427361\
5427316542731564273154623715426371542367154237615423716542371564237154\
6231754263175423617542316754231765423175642317546231574263157423615742\
3165742315674231576423157462315476231457623147562134765213467521346572\
1346527134562713452671345276134527163452713645271346521734652137465213\
4762513467251346275134267513427651342756134275163427513642751346257134\
2657134256713425761342571634257136425713462517342651734256173425167342\
5176342517364251734625137426513742561374251637425136742513764251374625\
1347621534672153462715342671534276153427165342715634271536427153462175\
3426175342167534217653421756342175364217534621573426157342165734215673\
4215763421573642157346215374261537421653742156374215367421537642153746\
2153476213546721354627135426713542761354271635427136542713564271354621\
7354261735421673542176354217365421735642173546213754261375421637542136\
7542137654213756421375462135742613574216357421365742135674213576421357\
4621354762134576213475621437652143675214365721436527143625714326571432\
5671432576143257164325714632571436275143267514327651432756143275164327\
5146327514362715432671543276154327165432715643271546327154362714532671\
4532761453271645327146532174635214763521467352146375214635721463527146\
3521746325174362517432651743256174325167432517643251746321574362157432\
6157432165743215674321576432157463217543621754326175432167543217654321\
7564321754632174562317456213745621734562174356217453621745632174653214\
7653214675321465732145672314567213456721435672145367214563721456732415\
7632415736241573264157324615732416573241567324516372415637241653724163\
5724163752416735241763524173652417356241735264173524617352416753241765\
3241756324175362417532647153246715324761352471635247136524713562471352\
6471352467135247613254716325471362547316245731624753162473516247315624\
7316524731625473612457361247536124735612473651247361524736125473621547\
3261547321654732156473215467321547632154736251473265147325614732516473\
2514673251476325147362541732654173256417325461732541673254176325417362\
5471326547132564713254671325476132457613247561324765132467513246571324\
6517324651372461537246135724613752461372546137245613724651327461532746\
1352746132574613275461327456132746513247615324716532471563247153624715\
3264751326457132645173264513726415372641357264137526413725641372654137\
2645132764153276413527641325764132756413276541327645132674153267413526\
7413256741326574132675413267451326475312647351264731526473125647312654\
7312645731264753216475326147532641753246175324167523416572341652734165\
2374165234716523417652341256734125637412563471256341725634127563412576\
3412536741253647125364172536412753641257364125376412534671253461725346\
1275346125734612537461253476125341672534162753416257341625374162534716\
2534176253412675341265734126537412653471265341726534127653412356741235\
6471235641723564127356412375641235764123546712354617235461273546123754\
6123574612354761235416723541627354162375416235741623547162354176235412\
6735412637541263574126354712635417263541276354123675412365741236547123\
654172365412736541237654123";
}

bool checkPalindrome(const char* input) {
	int length = strlen(input);
	for (int i = 0; i < length; i++)
		if (input[i] != input[length - i - 1])
			return false;
	return true;
}

bool checkPermute(const std::string& super, const std::string& permutation) {
	for (uint32_t i = 0; i < super.length(); i++) {
		for (uint32_t p = 0; p < super.length() - p; p++) {
			if (super[i + p] != permutation[p]) {
				break;
			}
			if (p == permutation.length() - 1) {
				return true;
			}
		}
	}
	return false;
}

void permute(const std::string& super,std::string a, int l, int r){
	if (l == r) {
		if (!checkPermute(super, a)){
			std::cout << "Unfound permutation:" << a << " in " << super << std::endl;
		}
	}
	else{
		for (int i = l; i <= r; i++){
			std::swap(a[l], a[i]);
			permute(super,a, l + 1, r);
			std::swap(a[l], a[i]);
		}
	}
}

bool checkSuper(const std::string& super, const std::string& vals) {
	if (!checkPalindrome(super.c_str())) {
		std::cout << vals << " Not Palendrome";
	}
	permute(super, vals, 0, vals.size() - 1);
	return false;
}

std::string generateSuper(const std::string& vals) {
	//Pre generate case for n=2
	if (vals.length() == 2) {
		return vals + vals[0];
	}
	//Example.
	/*     121
		 12 | 21
	12 3 12 | 21 3 21
		123121321 */
	//  123121321
	/*                              123121321
	     123    |    231    |    312    |    213    |    132    |    321
	  123 4 1   | 231 4 2   | 312 4 3   | 213 4 2   | 132 4 1   | 321 4 321
                        123412314231243121342132413214321 */
	                  //123412314231243121342132413214321
	//Get previous size
	std::string previus = vals.substr(0, vals.length() - 1);

	//Generate supermermentation for n - 1
	std::string supernminus1 = generateSuper(previus);

	//Create Subsets
	std::vector<std::string> sets;
	for (int i = 0; i < supernminus1.size() - previus.size() +1; i++) {
		sets.push_back(supernminus1.substr(i, previus.size()));
	}

	std::string center;
	//Make even
	if (sets.size() % 2 != 0) {
		center = sets[sets.size() / 2];
		sets.erase(sets.begin() + sets.size() /2);
	}
	else {
		//center = sets[sets.size() - 1].substr(previus.size() - 1);
		center = "2";
	}

	//Remove half
	sets.erase(sets.begin() + sets.size() / 2,sets.end());

	//Merge Subsets
	std::string half;
	char newchar = vals[vals.size() - 1];
	for (int i = 0; i < sets.size();i++) {
		half += sets[i];
		half += newchar;
		half += sets[i].substr(0,1);
	}
	half += center;

	std::string output;

	//Resize
	output.reserve((half.size() * 2) - 1);
	//add first half
	output += half;
	//remove center digits
	half.erase(half.end() - center.size(),half.end());
	//reverse
	std::reverse(half.begin(), half.end());
	//add second half
	output += half;
	return output;
}

void generateAndCheckSuper(const char* vars) {
	//TODO:
	std::string super = generateSuper(vars);
	checkSuper(super, vars);
}

int main(int argc, char* args) {
	generateAndCheckSuper("12345678");
	const char* super_4_2 = "123412314231243121342132413214321";
	checkSuper(Super::n2, "12");
	checkSuper(Super::n3, "123");
	checkSuper(Super::n4, "1234");
	checkSuper(Super::n5, "12345"); 
	checkSuper(Super::n6, "123456"); //Not Palendrome
	checkSuper(Super::n7, "1234567"); //Not Palendrome
	return EXIT_SUCCESS;
}